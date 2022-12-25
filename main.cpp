

#include <iostream>
#include "binaryTree.h"
using namespace std;

int main(){
    FinalTree<class T> item;
    int count = 0;
    T value;
    do{
        cout << "\nSample run:\n";

        cout << "New item? ";
        cin >> value;
        
        item.createNewNode(value);
        
        cout << "Printed in order..."
             << "\n----------------------\n";
        item.printInOrder();
        cout << "\nPrinted in pre order..."
             << "\n----------------------\n";
        item.printPreOrder();
        cout << "\nPrinted in post order..."
             << "\n----------------------\n";
        item.printPostOrder();
        
        count++;
    }while(count <= 30);
    
    cout << "\n\n";
    return 0;
}
