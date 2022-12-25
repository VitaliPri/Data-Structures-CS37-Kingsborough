#include <iostream>
using namespace std;
/*
 * First question is what DS is to use for storing nodes? Each node contains data and pointers to its children, thus we will use object and c++ it is class.
We can use pointers to link nodes
 In binary search tree (bst) node can have at most 2 children
 we can define node as object with 3 fields;
 field to store data;
 field is store address to left child;
 same as above to right;
 If there is no left or right child then address can be null (nullPtr)
 we can define node by using struct. it includes 3 elements.
 struct BstNode {
 int data // to stare date
 BstNode* left //  BstNode* means pointer to BstNode and here it stores address to left child
All nodes will be created in a dynamic memory (heap section) by
 way of new operator.
 As we know that any object created in heap can not be a variable
 or identifer, it only can be access through pointer
 New operator returns us pointer to the object created in heap
 To access (create) tree we need to know address of root node, then we
 can access all nodes by links.
 So we need create pointer to BstNode that will always store
 the address of root node
 BstNode* root; this is pointer to node to store address of
 root node; initially we can set root = null (to say that
 tree is empty)
 Leftmost cell is to store address of left child

 create node in heap
 BstNode* GetNewNode(int data){this function GetNewNode take
 int data as argument to be inserted and create a node in heap
 by using new and return back address of this node
 BstNode* newNode = new BstNode();
 new operator will return address of newnly created node BstNode()
which i store in newNode (which pointer to BstNode();
 Now using this new pointer newNode we can access of fields
 by dereference or arrow (same thing)
 (*newNode).data = data; set to data
 newNode->data= data;
  newNode -> left = newNode->right=NULL;
   return newNode; return address of new node


 to insert node in tree this is a function:
 void Insert(BstNode* root, int data){}
 function Insert take address of root node and data that will
 be inserted as argument
 Insert (root, 15); passing address to root and data 15
 then we insert another one



 */
struct BstNode {
    int data ;
    BstNode* left ;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    (*newNode).data = data;
    newNode -> left = newNode->right=NULL;
    return newNode;
};


void Insert(BstNode* root, int data);

int main() {
    BstNode* root = NULL;
    Insert (root, 15);
    Insert (root, 10);
    Insert (root, 20);
    return 0;
}
