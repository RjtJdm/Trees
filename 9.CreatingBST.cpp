#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Tree{
	public:
		int data;
		Tree *right;
		Tree *left;
};
Tree *root=NULL;
Tree *createNode(int data);
Tree *searchKey(int data){
	if(root==NULL)	return NULL;
	Tree *temp=root;
	Tree *prev=NULL;
	while(temp!=NULL){
		prev=temp;
		if(temp->data>data){
			temp=temp->left;
		}
		else if(temp->data<data){
			temp=temp->right;
		}
		else{
			return temp;
		}
	}
	return prev;	
}
void insert(){
	cout<<"Enter the data : ";
	int data;
	cin>>data;
	if(root==NULL)
	{
		root=createNode(data);
		cout<<"\nADDED FIRST NODE";
		return;
	}
	Tree *temp=root;
	Tree *prev=searchKey(data);
	if(prev->data==data){
		cout<<"CANNOT ADD DUPLICATE";
		return;
	}
	if(prev->data>data){
		prev->left=createNode(data);
	}
	else{
		prev->right=createNode(data);
	}
}
void inOrder(Tree *root){
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
Tree *createNode(int data){
	Tree *n=new Tree();
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void inorderIterative(Tree *root){
	if(root==NULL)	return;
	stack<Tree *> s;
	while(root!=NULL||!s.empty()){
		while(root!=NULL){
			s.push(root);
			root=root->left;
		}
		root=s.top();
		s.pop();
		cout<<root->data<<" ";
		root=root->right;
	}
}
void newTraversal(Tree *root){
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	if(root->right==NULL&&root->left==NULL)	{
		return;
	}
	if(root->left){
		cout<<"( ";
		newTraversal(root->left);
		cout<<")";
	}
	if(root->right){
		cout<<"( ";
		newTraversal(root->right);
		cout<<")";
	}
}
int main()
{
	int ch;
	 
	while(1){
		cout<<"\n1. INSERT ";
		cout<<"\n2. SHOW INORDER ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		if(ch==1){
			insert();
		}
		else if(ch==2){
			newTraversal(root);
			cout<<"\n";
			inorderIterative(root);
		}
		else{
			break;
		}
	}
}
