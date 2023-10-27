#include<iostream>
#define MAX 100
using namespace std;

class Node{
	int data;
	Node *left;
	Node *right;
	
	public:
		Node(int n){
			data =  n;
			left = NULL;
			right = NULL;
		}
		
		friend class tree;
};

class stack{
	int top;
	Node *item[MAX];
	public:
		stack(){
			top = -1;
		}
		void push(Node *p){
			item[++top] = p;
		}
		Node *pop(){
			return item[top--];	
		}
		int isfull(){
			return top == MAX;
		}
		int isempty(){
			return top == -1;
		}
};

class tree{
	Node *root;
	public:
		tree(){
			root = NULL;
		}
		
		void create();
		void search();
		void nonrec_inorder();
		void nonrec_preorder();
		void nonrec_postorder();
		void deleteNode(int n);
};

void tree::create(){
	Node *temp, *newnode;
	int n;
	char ans, c, choice;
	
	do{
		cout<<"Enter the element to be attached: ";
		cin>>n;
		newnode = new Node(n);
		if(root == NULL){
			root = newnode;
		}
		
		else{
			temp = root;
			while(1){
				if(n < temp->data){
					if(temp->left == NULL){
						temp->left = newnode;
						break;
					}
					else{
					temp = temp->left;
					}
				}
				else{
					if(temp->right == NULL){
						temp->right = newnode;
						break;
					}
					else{
						temp = temp->right;
					}
				}
				
			}
		}
		cout<<"Any more numbers?: ";
		cin>>ans;
	}
	while(ans == 'y' || ans == 'Y');
}

void tree::search(){
	int n;
	Node *temp;
	cout<<"Enter the number"<<endl;
	cin>>n;
	temp = root;
	while(1){
		if(n > temp->data){
			if(temp->right == NULL){
				break;
				cout<<"Number not found: "<<endl;
			}
			else{
				temp = temp->right;
			}
		}
		else if(n < temp->data){
			if(temp->left == NULL){
				break;
				cout<<"Number not found: "<<endl;
			}
			else{
				temp = temp->left;
			}
		}
		else{
			cout<<"Number Found At address: "<<temp<<endl;
			break;
		}
	}
}

void tree::nonrec_inorder(){
	Node *temp = root;
	stack s;
	cout<<"\nThe non recursive inorder traversal is: "<<endl;
	while(1){
		while(temp != NULL){
			s.push(temp);
			temp = temp->left;
		}
		if(s.isempty()){
			break;
		}
		temp = s.pop();
		cout<<temp->data<<" ";
		temp = temp->right;
	}
	cout<<endl;
}

void tree::nonrec_preorder(){
	cout<<"\nThe non recursive preorder traversal is: "<<endl;
	stack s;
	s.push(root);
	
	while(!s.isempty()){
		Node *temp = s.pop();
		
		if(temp != NULL){
			cout<<temp->data<<" ";
			s.push(temp->right);
			s.push(temp->left);
		}
	}
	cout<<endl;
	
}

void tree::nonrec_postorder(){
	cout<<"\nThe non recursive postorder traversal is: "<<endl;
	stack s1;
	stack s2;
	s1.push(root);
	while(!s1.isempty()){
		Node *temp = s1.pop();
		s2.push(temp);
		if(temp->left != NULL){
			s1.push(temp->left);
		}
		
		if(temp->right != NULL){
			s1.push(temp->right);
		}
	}
	
	while(!s2.isempty()){
		Node *temp2 = s2.pop();
		cout<<temp2->data<<" ";
	}
	cout<<endl;
}

void tree::deleteNode(int n){
	Node *temp, *parent = NULL, *father, *r, *son;
	temp = root;
	while((temp->data != n) && temp != NULL){
		if(n<temp->data){
			parent = temp;
			temp = temp->left;
		}
		else{
			parent = temp;
			temp = temp->right;
		}
	}
	if(temp == NULL){
		cout<<"Number not found"<<endl;;
		return;
	}
	if(temp->left == NULL){
		r = temp->right;
	}
	else{
		if(temp->right == NULL){
			r = temp->left;
		}
		else{
			father = temp;
			r = temp->right;
			son = r->left;
			while(son != NULL){
				father = r;
				r = son;
				son = r->left;
			}
			if( father != temp){
				father->left = r->right;
				r->right = temp->right;
			}
			r->left = temp->left;
		}
		if(parent == NULL){
			root = r;
		}
		else{
			if(temp == parent->left){
				parent->left = r;
			}
			else{
				parent->right = r;
			}
		}
		
		
	}
	
	delete temp;
	return;
}


int main(){
	tree t;
	int ch = 0;
	
	while(true){
		cout<<"Enter \n1) Create\t2) Pre-Order Display\t3) In-Order Display\t4) Post-Order Display\t5) Delete Node\t6) Search\t7) Exit"<<endl;
		cin>>ch;
		if(ch == 7){
			break;
		}
		switch(ch){
			case 1:
				t.create();
				break;
			case 2:
				t.nonrec_preorder();
				break;
			case 3:
				t.nonrec_inorder();
				break;
			case 4:
				t.nonrec_postorder();
				break;
			case 5:
				int n;
				cout<<"Enter Node to be deleted"<<endl;
				cin>>n;
				t.deleteNode(n);
				break;
			case 6:
				t.search();
				break;
			default:
				cout<<"Invalid Input"<<endl;
		}
	}
	
}
