	#include<iostream>
	#include<queue>    
	#include<stack>                                                                                                                         
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
	void postorder(Node *root){
		stack<Node*> stack1;
		stack<Node*> stack2;
		stack1.push(root);
		while(!stack1.empty()){
			Node *temp=stack1.top();
			stack2.push(temp);
			stack1.pop();
			if(temp->left)
				stack1.push(temp->left);
			if(temp->right)
				stack1.push(temp->right);
		}
		while(!stack2.empty()){
			Node *tem=stack2.top();
			stack2.pop();
			cout<<tem->data;
		}
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
		postorder(root);
		return 0;
	}
