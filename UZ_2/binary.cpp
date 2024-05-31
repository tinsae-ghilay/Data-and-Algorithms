#include "binary.h"
# include <iostream>


using namespace std;


BinaryTree::BinaryTree()=default;

BinaryTree::BinaryTree(int data) : data(data), left(nullptr), right(nullptr)
{
}

// insert data to root
BinaryTree* BinaryTree::insert(BinaryTree*root, int val)
{
    if(!root){
        cout << " "<<val;
        this->size_++;
        return new BinaryTree(val);
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
    cout << "Removing "<<val<<endl;

    // find value in tree
    root = find(root,val);
    if(root){
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
        if(rm){
            delete rm;
        }
        return;
    }else{
        cout <<val<< " doesnt exist in tree. Nothing was removed"<<endl;
    }
}

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

int BinaryTree::depth()
{
    return 0;//this->depth_;
}

BinaryTree *BinaryTree::find(BinaryTree *root, int value)
{
    if(!root){
        return nullptr;
    }
    if(root->data == value){
        return root;
    }
    if(root->data > value){
        return find(root->left,value);
    }else{
        return find(root->right,value);
    }
}
