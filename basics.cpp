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

Node* search(Node* root, int k)
{
    Node* temp=root;
    while(temp!=NULL&&temp->data!=k)
    {
        temp=k<temp->data?temp->left:temp->right;
    }
    return temp;
}

int findceil(Node* root, int key)
{
    int ceil_element=-1;
    while(root!=NULL)
    {
        if(root->data==key)
        {
            ceil_element=root->data;
            return ceil_element;
        }
        if(key>root->data)
        {
            root=root->right;
        }
        else 
        {
            ceil_element=root->data;
            root=root->left;
        }
    }
    return ceil_element;
}

int findfloor(Node* root, int key)
{
    int floor_element=-1;
    while(root!=NULL)
    {
        if(root->data==key)
        {
            floor_element=root->data;
            return floor_element;
        }
        if(key>root->data)
        {
            floor_element=root->data;
            root=root->right;
        }
        else 
        {
            root=root->left;
        }
    }
    return floor_element;
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
}