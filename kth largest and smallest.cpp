/*
Find kth smallest and largest element in the BST
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

void find_kth_smallest_inorder(Node* root,int k, int &count)
{
    if(root==NULL) return;
    find_kth_smallest_inorder(root->left,k,count);
    count++;
    if(count==k)
    {
        cout<<"kth smallest "<<root->data<<endl;
    }
    find_kth_smallest_inorder(root->right,k,count);
}

void find_kth_largest_inorder(Node* root, int k, int &count)
{
    if(root==NULL) return;
    find_kth_largest_inorder(root->right,k,count);
    count++;
    if(count==k)
    {
        cout<<"kth largest "<<root->data<<endl;
    }
    find_kth_largest_inorder(root->left,k,count);
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void find_kth_smallest_Morris_Traversal(Node* root, int k)
{
    Node* current=root;
    int count=1;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            count++;
            current=current->right;
        }
        else 
        {
            Node* prev=current->left;
            while(prev->right!=NULL&&prev->right!=current)
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
                count++;
                prev->right=NULL;
                current=current->right;
            }
        }
        if(count==k)
        {
            cout<<"kth smallest "<<current->data<<endl;
            break;
        }
    }
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
    //find_kth_smallest(root,3);
    inorder(root);
    int count=0;
    cout<<endl;
    find_kth_smallest_inorder(root,3,count);
    count=0;
    find_kth_largest_inorder(root,4,count);
}