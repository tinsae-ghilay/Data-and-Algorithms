#include "binary.h"
# include <iostream>


using namespace std;


BinaryTree::BinaryTree()=default;

BinaryTree::BinaryTree(int data) : data(data), left(nullptr), right(nullptr) {}

// insert data to root
BinaryTree* BinaryTree::insert(BinaryTree*root, int data)
{
    if(!root){
        cout << " "<<data;
        this->size_++;
        return new BinaryTree(data);
    }
    if(data > root->data){
        root->right = insert(root->right,data);
    }else{
        root->left = insert(root->left,data);
    }
    return root;
}


// removes a teree whose data is = @param data
// reataches binary tree  
void BinaryTree::remove(BinaryTree *root, int data)
{
    if(!root){
        return;
    }
    if(root->data == data){
        cout << "removing "<<data<<endl;
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
        if(rm){
            delete rm;
        }
        return;
    }else{
        if(root->data > data){
            remove(root->left,data);
        }else{
            remove(root->right,data);
        }
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

BinaryTree *BinaryTree::find(BinaryTree *root, int data)
{
    if(root->data == data){
        return root;
    }else{
        return (root->data > data) ? find(root->right, data) : find(root->left, data);
    }
}
