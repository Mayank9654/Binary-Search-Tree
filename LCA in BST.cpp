/*
LCA in Binary Search Tree
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

Node* LCA_BST_recursiveapproach(Node* root, Node* n1, Node* n2)
{
    if(root==NULL) return NULL;
    if(root->data<n1->data&&root->data<n2->data)
    {
        return LCA_BST_recursiveapproach(root->right,n1,n2);
    }
    if(root->data>n1->data&&root->data>n2->data)
    {
        return LCA_BST_recursiveapproach(root->left,n1,n2);
    }
    return root;
}


Node *LCA_BST(Node *root, Node *n1, Node *n2)
{
    while (root!=NULL)
    {
        if (root->data > n1->data && root->data > n2->data)
            root = root->left;
        else if (root->data < n1->data && root->data < n2->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
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
    Node* n1=new Node(6);
    Node* n2=new Node(4);
    cout<<endl<<LCA_BST(root, n1,n2)->data<<endl;
    cout<<LCA_BST_recursiveapproach(root, n1,n2)->data<<endl;
}