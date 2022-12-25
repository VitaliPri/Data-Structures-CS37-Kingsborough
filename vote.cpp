#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;
int main(){
    vector<vector<int> > votersID;
    bool voted = 0, found, end = false;
    int userID, choice, lcount, kcount, mcount ; string line;
    do{
        ofstream votersIDFile;
        votersIDFile.open("voterIDNo.txt");
        for(int i = 4000; i <= 4200; i++)
        {
            if(voted == 0)
                votersIDFile << i << "\t" << voted << endl;
        }
        votersIDFile.close();
        cout << "Welcome to the Kingsborough CS EVOTE System\n"
             << "--------------------------------------------"
             << "\nVoter ID?(Enter 0 to exit) ";
        cin >> userID;
        if(userID == 0)
            return 0;
        ofstream recordFile("AuditTrail.txt", ios::app);
        recordFile << userID << endl;
        recordFile.close();
        ifstream openVotersID;
        openVotersID.open("voterIDNo.txt");
        if(!openVotersID.is_open())
            cout << "There are no such file!";
        else{
            int item;
            while(openVotersID >> item)
            {
                vector<int> tmpVec;
                tmpVec.push_back(item);
                votersID.push_back(tmpVec);
            } }
        openVotersID.close();
        for (int i = 0; i < votersID.size(); i++){
            cout << votersID[i].size() << endl;
            for(int j = 0; j < votersID[i].size();
                    if(userID == votersID[i][j]){
                        found == true;
                        if(votersID[i+1][j] == 0){
                            votersID[i+1][j] = 1;
                            cout << "WELCOME!\n"
                                 << "EVOTE\n"
                                 << "-------\n"
                                 << "1) Kathy Hochul\n"
                                 << "2) Lee Zeldin\n"
                                 << "3) Mickey Mouse\n"
                                 << "Your choice? ";
                            cin >> choice;
                            ofstream evoteFile("tally.txt");
                            switch(choice){
                                case 1:
                                case 1:
                                    kcount++;
                                    evoteFile << "Kathy Hochul" << "\t" << kcount << endl;
                                    evoteFile << "Lee Zeldin" << "\t" << lcount << endl;
                                    evoteFile << "Mickey Mouse" << "\t" << mcount << endl;
                                    break;
                                case 2:
                                    lcount++;
                                    evoteFile << "Kathy Hochul" << "\t" << kcount << endl;
                                    evoteFile << "Lee Zeldin" << "\t" << lcount << endl;
                                    evoteFile << "Mickey Mouse" << "\t" << mcount << endl;
                                    break;
                                case 3:
                                    mcount++;
                                    evoteFile << "Kathy Hochul" << "\t" << kcount << endl;
                                    evoteFile << "Lee Zeldin" << "\t" << lcount << endl;
                                    evoteFile << "Mickey Mouse" << "\t" << mcount << endl;
                                    break;
                            }
                            evoteFile.close();
                            ofstream recordFile("AuditTrail.txt", ios::app);
                            recordFile << choice << endl;
                            recordFile.close();
                        }
                        else
                            cout << "YOU VOTED ALREADY! No fraud allowed here!\n";
                    }
                    else
                        found == false;
        } }
    if(found == false) {
        cout << userID
             << " is not a valid ID in this district! Go to your own voting district where ever that is!"
             << "\nHave a nice day.";
    }
}while(end != true);
cout << "\n\n";
return 0;
}