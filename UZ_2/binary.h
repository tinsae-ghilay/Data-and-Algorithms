/*
* created by TGK on may 30, 2024
* for Algoritms and data structures
*/

#ifndef BINARY_H
#define BINARY_H


class BinaryTree{
private:
    int size_ = 0;
    int depth_ = 0;
    int data;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
public:

    BinaryTree();
    explicit BinaryTree(int data);
    ~BinaryTree();

    // insert an element
    BinaryTree* insert(BinaryTree* root, int data);
    // remove an element
    void remove(BinaryTree* root, int data);

    // travesrsal - pre order
    void preOrder(BinaryTree *node);

    // travesrsal - in order
    void inOrder(BinaryTree *node);

    // travesrsal - post order
    void postOrder(BinaryTree *node);

    // tree size
    int size();

    // tree depth
    int depth(BinaryTree* tree);

    BinaryTree * find(BinaryTree* root, int data);

    void resetLink(BinaryTree* root, int value);
};

#endif // BINARY_H