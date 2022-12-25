#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

enum c_suit{
    Diamonds, Clubs, Hearts, Spades
};
struct account{
    string username; //the username of this account
    int wins;
};
struct Card{
    c_suit suite;   // Suite of the card the player has, ex diamonds or spades
    int c_value;    // Value of card
    bool face_up;   // since one card is facing down
};
struct user{
    account info; //player's account info
    vector<Card> hand; //the players hand
};

// Prototypes
Card create_card();
Card hitMe();
int score(vector<Card>);
bool hasAce(vector<Card>);
void printCards(vector<Card>);
char printSuite(Card);
int winner(user, user&);
void result(user, user&);
void split(user&, user&);
void play(vector<user>&);
void clear(vector<Card>&);
void dealer_play(user&);

int main(){
    user player;
    user dealer;
    vector<user> users;
    dealer.info.username = "Dealer";
    users.push_back(dealer);
    int choice;
    char again;

    cout << "1)Play BlackJack\n"
         << "2)Quit\n";
    cin >> choice;

    switch (choice) {
        case 1:
            cin.ignore();
            cout << "What is the username you would like to use? ";
            getline(cin, player.info.username);
            users.push_back(player);
            play(users);
            break;

        case 2:
            return 0;
    }

    do{
        cout << player.info.username << " won: " << player.info.wins << endl;
        cout << "Play again?(Y/N)";
        cin >> again;

        if(again == 'Y' || again == 'y'){
            play(users);
        }else
            continue;
    }while (!(again == 'N' || again == 'n'));

    cout << "\n\n";
    return 0;
}

void play(vector<user> &players){
    char input = '\0';

    for(int i=1; i<(players.size()*2); i++){  // runs through each player and gives them 2 cards
        // We store the card in the players hand
        players[(i%players.size())].hand.push_back(create_card());
        if((i%players.size()) == 0 && (i%2) == 0)
            players[(i%players.size())].hand[(i%2)].face_up = false;
//        cout << (i%players.size()) << endl;
    }

    // show player score but not the dealer
//    for(int i=1; i<players.size(); i++){
//        cout << players[i].info.username << " has: " << score(players[i].hand) << endl;
//    }

    // Print each player card
    for(int i = 0; i < players.size(); i++){
        cout << players[i].info.username << " cards: " << endl;
        printCards(players[i].hand);
        cout << endl;
    }
    bool BJ = true;
    for(int i = 1; i < players.size(); i++){
        do{

            if(players[0].hand[1].c_value == 1 && BJ){
                if(score(players[0].hand) == 21){
                    players[0].hand[0].face_up = true; //if they do we set the first card to face up

                    printCards(players[0].hand); //prints the dealers cards

                    for(int i =1;i<players.size();i++){
                        result(players[0],players[i]);
                    }
                    input = 'S';
                }
                BJ = false;
            }

            if(players[0].hand[1].c_value >= 10 && BJ){
                if(score(players[0].hand) == 21){
                    players[0].hand[0].face_up = true;

                    printCards(players[0].hand); //prints the dealers card

                    for(int i =1;i<players.size();i++){
                        result(players[0],players[i]);
                    }
                    input = 'S';
                }
                BJ = false;
            }

            if(score(players[0].hand) <= 21){
                if(((players[i].hand[0].c_value >= 10 && players[i].hand[1].c_value >= 10) || (players[i].hand[0].c_value == players[i].hand[1].c_value)) && players[i].hand.size() == 2){
                    cout << players[i].info.username << " score: " << score(players[i].hand) << endl;
                    cout << "split(L), take a hit(H), or stay(S)? Default is to take a stay... " << endl;
                }
                else{
                    cout << players[i].info.username << " score: " << score(players[i].hand) << endl;
                    cout << "take a hit(H), or stay(S)? Default is to take a stay... " << endl;
                }
                cin >> input;
                switch(input){
                    case 'L':
                        split(players[0], players[i]);
                        printCards(players[i].hand);
                        break;
                    case 'H':
                        players[i].hand.push_back(hitMe());
                        printCards(players[i].hand);
                        cout << players[i].info.username << " score is now: " << score(players[i].hand) << endl;
                        break;
                    default:
                        input = 'S';
                }
                if(score(players[i].hand) > 21)
                    input = 'S';
            }
        }while(!(input == 'S' || input == 's'));
    }

    dealer_play(players[0]);

    players[0].hand[0].face_up = true;

    // Players cards and scores everyone
    for(int i = 0; i < players.size(); i++){
        cout << players[i].info.username << " score: " << score(players[i].hand) << ", Cards: ";
        printCards(players[i].hand);
    }

    for(int i = 1; i < players.size(); i++){
        if(score(players[i].hand) > 21)
            cout << "YOU BUSTED!\n";
        int win = winner(players[0], players[i]);
        if(win == 1)
            players[i].info.wins += 1;
        result(players[0], players[i]);
        clear(players[i].hand);
    }
    clear(players[0].hand);
}
/*
creates a new card with a random num between 1-13 and set a suite
to the card also and returns it
 */
Card create_card(){
    Card newCard;

    newCard.c_value = 1 + rand() % 13; // The val is between 1 and 13
    int suite = rand() % 4;
    switch (suite) {
        case 0:
            newCard.suite = Spades;
            break;
        case 1:
            newCard.suite = Diamonds;
            break;
        case 2:
            newCard.suite = Hearts;
            break;
        case 3:
            newCard.suite = Clubs;
            break;
    }
    newCard.face_up = true;
    return newCard;
}

// Get scores for the players
int score(vector<Card> hand){
    int total_score = 0;
    for(int i = 0; i < hand.size(); i++){
        if(hand[i].c_value >= 10)
            total_score += 10;
        else
            total_score += hand[i].c_value;
    }

    if(hasAce(hand) && total_score <= 11)
        total_score += 10;

    return total_score;
}

// Print cards
void printCards(vector<Card> hand){
    const string C_value[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "X"};

    for(int i = 0; i < hand.size(); i++){
        if(hand[i].face_up)
            cout << C_value[ (hand[i].c_value-1) ] << printSuite(hand[i]) << " ";
        else
            cout << C_value[13] << C_value[13] << " ";
    }
    cout << "\n";
}

// return a char representing the suite
char printSuite(Card newCard){
    switch(newCard.suite){
        case 0:
            return 'S';
        case 1:
            return 'D';
        case 2:
            return 'H';
        case 3:
            return 'C';
    }
}

// if the hand has ace
bool hasAce(vector<Card> hand){
    bool has_ace = false;
    for(int i = 0; i < hand.size(); i++){
        if(hand[i].c_value == 1)
            has_ace = true;
    }
    return has_ace;
}

// split cards
void split(user &dealer, user &player){
    user split;
    vector<user> users;
    users.push_back(dealer);

    split.hand.push_back(player.hand[0]);
    split.hand.push_back(create_card());
    player.hand[0] = create_card();

    split.info.username = player.info.username;
    users.push_back(split);

    printCards(users[1].hand);

    char input = '\0';
    do{
        for(int i = 1; i < users.size(); i++){
            if(score(users[i].hand) > 21)
                input = 's';
            else{
                cout << "Hit(H) or Stay(S): ";
                cin >> input;
            }

            // If they choose to hit, give them a new card
            if(input == 'H' || input == 'h'){
                users[i].hand.push_back(hitMe());
                printCards(users[i].hand);
                cout << users[i].info.username << " score is now: " << score(users[i].hand) << endl;
            }
        }
    }while(!(input == 'S' || input == 's'));

    dealer_play(users[0]);

    for(int i = 1; i < users.size(); i++){
        cout << users[i].info.username << " score: " << score(users[i].hand) << ", Cards: " << endl;
        printCards(users[i].hand);
        if(score(users[i].hand) > 21)
            cout << "YOU BUSTED!\n";
        result(users[0], users[i]);
    }
}

// new card for player
Card hitMe(){
    return create_card();
}

void dealer_play(user &dealer){
    if(( score(dealer.hand) < 17 ) || ( score(dealer.hand) == 17  && hasAce(dealer.hand)))
        dealer.hand.push_back(hitMe());
}

// Who won the game
int winner(user dealer, user &player){
    if(score(dealer.hand) == score(player.hand))    // No one wins
        return 0;
    else if(((score(dealer.hand) < score(player.hand)) && (score(player.hand) <= 21)) || (score(dealer.hand) > 21 && score(player.hand) <= 21))    // User wins
        return 1;
    else    // Dealer wins
        return -1;
}

void result(user dealer, user &player){
    if(winner(dealer, player) == 1){
        if(score(player.hand) == 21 && hasAce(player.hand) && player.hand.size() == 2)
            cout << player.info.username << " WON!\n" << endl;
        else
            cout << player.info.username << " WON!\n" << endl;
    }
    else if (winner(dealer, player) == 0)
        cout << player.info.username << " TIED!\n" << endl;
    else
        cout << player.info.username << " LOST! Good Luck Next Time!\n" << endl;
}

// clear player's hand
void clear(vector<Card> &hand){
    hand.clear();
}

