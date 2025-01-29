/*
Binary Search Tree Iterator | BST | O(H) Space
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

class BSTIterator
{
    stack<Node*> st;
    public:
    BSTIterator(Node* root)
    {
        pushALL(root);
    }
    
    //return if there is a next smallest element
    bool hasnext()
    {
        return !st.empty();
    }
    
    //return the next smallest number
    int next()
    {
        Node* temp=st.top();
        st.pop();
        pushALL(temp->right);
        return temp->data;
    }
    
    private:
    void pushALL(Node* node)
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
    }
};

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