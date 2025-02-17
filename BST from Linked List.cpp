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

class ListNode
{
    public:
    int data;
    ListNode* next;
    ListNode(int data1)
    {
        data=data1;
        next=nullptr;
    }
    ListNode(int data1, ListNode* next1)
    {
        data=data1;
        next=next1;
    }
};

ListNode* convertArrayToLinkedList(vector<int>a)
{
    ListNode* head=new ListNode(a[0]);
    ListNode* prev=head;
    for(int i=1;i<a.size();i++)
    {
        ListNode* temp=new ListNode(a[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* createTree(vector<int>&a, int low, int high)
{ 
    if(low>high) return NULL;
    int mid=low+(high-low)/2;
    Node* root=new Node(a[mid]);
    root->left=createTree(a,low,mid-1);
    root->right=createTree(a,mid+1,high);
    return root;
}
Node* sortedListToBST(ListNode* head) 
{
    if(head==NULL) return NULL;
    ListNode* temp=head;
    vector<int>a;
    while(temp!=NULL)
    {
        a.push_back(temp->data);
        temp=temp->next;
    }
    return createTree(a,0,a.size()-1);
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
    vector<int>a={1,2,3,4,5,6};
    ListNode* head=convertArrayToLinkedList(a);
    Node* root=sortedListToBST(head);
    iterativepreorder(root);
}