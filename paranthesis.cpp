#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkIfParenthesisBalanced(const string);

int main(){
    string exp, parenth;
    bool valid = true;
    do{
        exp = "";
        valid=true;
        cout << "Please enter an mathematical expression.\n";
        getline(cin, exp);
        
        cout << exp.at(exp.length()-1) << endl;
        if(exp.back()!=';'){
            cout << "Syntax error!  Missing semicolon!\n";
            valid = false;
        }

        for(int i=0; i<exp.length(); i++){
            if(exp[i] == '(' || exp[i] == ')') parenth.push_back(exp[i]);
        }
//        cout << parenth << endl;
        checkIfParenthesisBalanced(parenth)? cout << "\nBalanced": cout << "\nNot balanced";
        
        
    }while(valid == false);
    
    
    cout << "\n\n";
    return 0;
}

int checkIfParenthesisBalanced(string expression){
//    vector<char> t;
//
//    for(int i=0; i<expression.length(); i++){
//        if(expression[i] == '(' || expression[i] == ')')
//            t.push_back(expression[i]);
//        if(t[0] == '(' && t[t.size()-1] == ')'){
//            return checkIfParenthesisBalanced(t);
//        }
//    }
    
    long int Size = expression.length();
    cout << expression << endl;
    if(Size>1){
        if(expression.at(0) == '(' && expression.at(Size-1) == ')')
            return checkIfParenthesisBalanced(expression.substr(1,Size-2));
            /*
             ((()))
             (())
             ()
             */
        else
            return false;
    }
    else if(Size == 1)
        return false;
    
    else if (Size == 0)
        return true;
    
    else
        return true;
}
