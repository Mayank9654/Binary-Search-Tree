/*
Binary Search Tree Iterator from sorted array
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

Node* helper(vector<int>&a, int start, int end)
{
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    Node* root = new Node(a[mid]);
    root->left=helper(a,start,mid-1);
    root->right=helper(a,mid+1,end);
    return root;
}
Node* sortedArrayToBST(vector<int>& a) 
{
    if(a.size()==0) return NULL;
    return helper(a,0,a.size()-1);
}

void iterativepreorder(Node* root)
{
    if(root==NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
}

int main()
{
    vector<int> a={1,2,3,4,5,6,7};
    Node* root=sortedArrayToBST(a);
    iterativepreorder(root);
}