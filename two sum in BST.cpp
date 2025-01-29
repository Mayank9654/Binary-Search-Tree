/*
Two Sum in BST
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data1)
    {
        data=data1;
        left=nullptr;
        right=nullptr;
    }
    Node(int data1, Node* left1, Node* right1)
    {
        data=data1;
        left=left1;
        right=right1;
    }
};

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root=new Node(5);
    root->left=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right=new Node(7);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    inorder(root);
}