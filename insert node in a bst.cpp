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

Node* insertNode(Node* root, int k)
{
    if(root==NULL) return new Node(k);
    Node* temp=root;
    while(true)
    {
        if(temp->data<=k)
        {
            if(temp->right!=NULL) temp=temp->right;
            else 
            {
                temp->right=new Node(k); 
                break;
            }
        }
        else
        {
            if(temp->left!=NULL) temp=temp->left;
            else 
            {
                temp->left=new Node(k); 
                break;
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
    Node* node_to_be_searched=search(root,1);
    cout<<node_to_be_searched->data<<endl;
    cout<<findceil(root, 6)<<endl;
    cout<<findfloor(root,6)<<endl;
    inorder(root);
    cout<<endl;
    Node* root1 = insertNode(root, 5);
    inorder(root1);
    cout<<endl;
}