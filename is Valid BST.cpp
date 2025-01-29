/*
Check if a tree is a BST or BT | Validate a BST
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

bool isValidBST(Node* root, long minVal, long maxVal)
{
    if(root==NULL) return true;
    if(root->data>=maxVal||root->data<=minVal) return false;
    return ((root->left, minVal, root->data)&&(root->right, root->data, maxVal));
}

bool isValidBST_Morris_Traversal(Node* root)
{
    Node* current=root;
    int tree_value=INT_MIN;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            if(tree_value<current->data)
                tree_value=current->data;
            else
                return false;
            current=current->right;
        }
        else
        {
            Node* prev=current->left;
            while(prev->right!=current&&prev->right!=NULL)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=current;
                current=current->left;
            }
            else
            {
                if(tree_value<current->data)
                    tree_value=current->data;
                else
                    return false;
                prev->right=NULL;
                current=current->right;
            }
        }
    }
    return true;
}


void Morris_Traversal(Node* root)
{
    Node* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current=current->right;
        }
        else
        {
            Node* prev=current->left;
            while(prev->right!=current&&prev->right!=NULL)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=current;
                current=current->left;
            }
            else
            {
                cout<<current->data<<" ";
                prev->right=NULL;
                current=current->right;
            }
        }
    }
}


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
    cout<<endl<<isValidBST(root, INT_MIN, INT_MAX)<<endl;
    Morris_Traversal(root);
    cout<<endl<<isValidBST_Morris_Traversal(root)<<endl;
}