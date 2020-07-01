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
	void BFS(Node *root){
		queue<Node*> queue;
		queue.push(root);
		while(!queue.empty()){
			Node *t=queue.front();
			cout<<t->data;
			queue.pop();
			if(t->left!=NULL){
				queue.push(t->left);
			}
			
			if(t->right!=NULL){
				queue.push(t->right);
			}
		}
		
	}
	int main()
	{	
		cout<<"INSERTED 10 Elements\n";
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
		BFS(root);
		return 0;
	}
