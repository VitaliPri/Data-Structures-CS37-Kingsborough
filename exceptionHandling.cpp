#include <iostream>
using namespace std;

int main() {

    int numerator, denominator, result;

    cout << "Please, enter numerator and denominator: " << endl;
    cin >> numerator >> denominator;

    try{ // in try block is where we write the code that bug might occur
        if (denominator == 0){
            throw 404; // here 404 is any number that related to particula error
        }
    } catch (int x ) {// catch block is what to do if there is bug; here x is placeholder for error (404)
        cout << "Error: " << x << " SORRY - You are not allowed to divide by 0 ! Learn math !" <<endl;
    }

    // if denominator not equal to 0 it will skip catch block
    return 0;
}
