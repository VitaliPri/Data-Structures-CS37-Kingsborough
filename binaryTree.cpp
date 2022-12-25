#include <iostream>
#include "binaryTree.h"
using namespace std;

template <class T>
void FinalTree<T>::insert(FinalTree *&nodePtr, FinalTree *&newNode){
    if(nodePtr == nullptr)
        nodePtr = newNode;
    else if(newNode->data < nodePtr->data)
        insert(nodePtr->lChildPtr, newNode);
    else
        insert(nodePtr->rChildPtr, newNode);
}

template <class T>
void FinalTree<T>::createNewNode(T val){
    FinalTree* newNode = new FinalTree();
    newNode->data = val;
    newNode->lChildPtr = newNode->rChildPtr = nullptr;
    
    insert(root, newNode);
}

template <class T>
void FinalTree<T>::printInOrderPrivate(FinalTree *nodePtr) const
{
    if(nodePtr){
        printInOrderPrivate(nodePtr->lChildPtr);
        cout <<nodePtr->data << endl;
        printInOrderPrivate(nodePtr->rChildPtr);
    }
}

template <class T>
void FinalTree<T>::printPreOrderPrivate(FinalTree *nodePtr) const
{
    if(nodePtr){
        cout << nodePtr->data << endl;
        printPreOrderPrivate(nodePtr->lChildPtr);
        printPreOrderPrivate(nodePtr->rChildPtr);
    }
}

template <class T>
void FinalTree<T>::printPostOrderPrivate(FinalTree *nodePtr) const
{
    if(nodePtr){
        printPostOrderPrivate(nodePtr->lChildPtr);
        printPostOrderPrivate(nodePtr->rChildPtr);
        cout << nodePtr->data << endl;
    }
}

