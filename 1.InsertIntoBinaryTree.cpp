	#include<iostream>
	#include<queue>                                                                                                                             
	using namespace std;
	class Node
	{
	public:
		int data;
		Node *left;
		Node *right;

	};
	Node *root=NULL;
	Node* makeNode(int d,Node *l,Node *r){
		Node *newNode=new Node();
		newNode->data=d;
		newNode->right=r;
		newNode->left=l;
		return newNode;
	}
	queue<Node*> q;
	void insert(){
		cout<<"Enter the Node data";
		int d;
		cin>>d;
		Node *n=makeNode(d,NULL,NULL);
		if(root==NULL){
			root=n;
			q.push(root);
			return;
		}
		Node *t=q.front();
		if(t->left!=NULL&&t->right!=NULL){
			q.pop();
			t=q.front();
		}
		if(t->left==NULL){
			t->left=n;
			q.push(n);
		}
		else if(t->right==NULL){
			t->right=n;
			q.push(n);
		}
	}
	void inOrder(Node *root){
		if(root==NULL)	return;
		inOrder(root->left);
		cout<<root->data;
		inOrder(root->right);
	}
	int main()
	{	
		insert();
		insert();
		insert();		
		insert();	
		insert();	
		insert();		
		insert();		
		insert();		
		insert();		
		insert();
		cout<<"INSERTED 10 Elements";
		inOrder(root);
		return 0;
	}
