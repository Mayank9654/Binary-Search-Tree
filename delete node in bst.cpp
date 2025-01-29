/*
Search in a binary search tree 
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

Node* findLastRight(Node* root)
{
    if(root->right==NULL) return root;
    return findLastRight(root->right);
}

Node* helper(Node* root)
{
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;
    Node* rightchild=root->right;
    Node* lastright=findLastRight(root->left);
    lastright->right=rightchild;
    return root->left;
}

Node* deleteNodeinBST(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return helper(root);
    }
    Node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data>key)
        {
            if(temp->left!=NULL&&temp->left->data==key)
            {
                temp->left=helper(temp->left);
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
        else 
        {
            if(temp->right!=NULL&&temp->right->data==key)
            {
                temp->right=helper(temp->right);
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
    }
    return root;
}

int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right=new Node(7);
    inorder(root);
    cout<<endl;
    Node* root2=deleteNodeinBST(root,2);
    inorder(root);
}