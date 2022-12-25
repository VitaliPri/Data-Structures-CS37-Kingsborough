#ifndef binaryTree_h
#define binaryTree_h

template<class T>
class FinalTree{
private:
    T data;   // The data in the node
    FinalTree *lChildPtr;
    FinalTree *rChildPtr;
    
    FinalTree *root;
    void insert(FinalTree *&, FinalTree *&);
    void printInOrderPrivate(FinalTree *) const;
    void printPreOrderPrivate(FinalTree *) const;
    void printPostOrderPrivate(FinalTree *) const;
public:
    FinalTree(){root = nullptr;}
    void createNewNode(T);
    void printInOrder() const
        {  printInOrderPrivate(root); }
    void printPreOrder() const
        {  printPreOrderPrivate(root); }
    void printPostOrder() const
        {  printPostOrderPrivate(root); }
};

#endif
