#include "binary.h"
# include <iostream>


using namespace std;


BinaryTree::BinaryTree()=default;

BinaryTree::BinaryTree(int data) : data(data), left(nullptr), right(nullptr){ }

BinaryTree::~BinaryTree(){
    delete this->left;
    delete this->right;
}

// insert data to root
BinaryTree* BinaryTree::insert(BinaryTree*root, int val)
{
    if(!root){
        cout << " "<<val;
        this->size_++;
        root = new BinaryTree(val);
        return root;
    }
    if(val > root->data){
        root->right = insert(root->right,val);
    }else{
        root->left = insert(root->left,val);
    }
    return root;
}


// removes a tree whose data is = @param data
// reataches binary tree  
void BinaryTree::remove(BinaryTree *root, int val)
{
    auto old = root;
    root = find(root,val);

    if(root){
        // find value in tree
        if(root->left == nullptr && root->right == nullptr) {
            resetLink(old,val);
            cout<<val << " was removed"<<endl;
            this->size_--;
            return;
        }
        auto pr = root;
        auto rm = root->right;
        while (rm)
        {
            if(rm->left){
                pr = rm;
                rm = rm->left;
            }else if(rm->right){
                pr = rm;
                rm = rm->right;
            }else{
                break;
            }
        }

        if(pr->left == rm){
            pr->left = nullptr;
        }else{
            pr->right = nullptr;
        }

        root->data = rm->data;
        this->size_--;
		delete rm;
        cout<<val << " was removed"<<endl;
        return;
    }
    cout <<"Tried removing "<<val<< ", but it was not found"<<endl;
}

// Preorder traversal recursive
//
void BinaryTree::preOrder(BinaryTree *tree)
{
   if(tree){
        cout <<" "<< tree->data;
        preOrder(tree->left);
        preOrder(tree->right);
   }
}

void BinaryTree::inOrder(BinaryTree *tree)
{
    if(tree){
        inOrder(tree->left);
        cout <<" "<< tree->data;
        inOrder(tree->right);
    }
}

void BinaryTree::postOrder(BinaryTree *tree)
{

    if(tree){
        postOrder(tree->left);
        postOrder(tree->right);
        cout <<" "<< tree->data;
    }
}

int BinaryTree::size()
{
    return this->size_;
}

int BinaryTree::depth(BinaryTree* tree)
{
    if(!tree) {
        return 0;
    }
    int left = depth(tree->left);
    int right = depth(tree->right);
    return max(left,right)+1;
}

BinaryTree *BinaryTree::find(BinaryTree *root, int value)
{
    if(!root || root->data == value){
        (root)? cout<<"": cout <<value <<" was not found"<<endl;
        return root;
    }
    if(root->data > value){
        return find(root->left,value);
    }
    return find(root->right,value);
}

void BinaryTree::resetLink(BinaryTree* root, int value) {
    if(!root) {
        return;
    }
    if(root->data > value) {
        if(root->left->data == value) {
            delete root->left;
            root->left = nullptr;
        }else {
            resetLink(root->left,value);
        }
    }else {
        if(root->right->data == value){
            delete root->right;
            root->right = nullptr;
        }else {
            resetLink(root->right,value);
        }
    }
}


