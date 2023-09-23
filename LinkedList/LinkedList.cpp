#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
};
class List:public Node{
	Node *listptr, *temp;
	Node *listptr2, *temp2;
	public:
	List(){
		listptr=NULL;
		temp=NULL;
	}
	void create();
	void display();
	void insertStart();
	void insertEnd();
	void insertInBetween();
	void deleteNode();
	void reverse();
	void concatnate(List, List);
};

void List::create(){
	int n,i,x;
	cout<<"Enter total number of nodes: ";
	cin>>n;
	for(int i=0; i<n; i++){
		Node* newnode = new Node;
		cout<<"Enter Data: ";
		cin>>x;
		newnode->data = x;
		newnode->next = NULL;
		if(listptr==NULL){
			listptr = newnode;

		temp = newnode;
		}
		else{
			temp->next = newnode;
			temp = newnode;
		}
	}
}

void List::display(){
	temp = listptr;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL";
}

void List::insertStart(){
	int x;
	Node* newnode = new Node;
	cout<<"\nEnter Data: ";
	cin>>x;
	newnode->data = x;
	newnode->next = NULL;
	newnode->next = listptr;
	listptr = newnode;
}

void List::insertEnd(){
	int x;
	Node* newnode = new Node;
	cout<<"\nEnter Data: ";
	cin>>x;
	newnode->data = x;
	newnode->next = NULL;
	temp = listptr;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
}

void List::insertInBetween(){
	int x, n;
	temp = listptr;
	Node *newnode = new Node;
	cout<<"Enter Data"<<endl;
	cin>>x;
	newnode->data = x;
	newnode->next = NULL;
	cout<<"Enter Position"<<endl;
	cin>>n;
	for(int i=1; i<n-1; i++){
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void List::deleteNode(){
	int n;
	temp = listptr;
	Node *temp2;
	cout<<"Enter position of node to be deleted"<<endl;
	cin>>n;
	if(n==1){
		Node *del = listptr;
		listptr = listptr->next;
		delete del;
	}
	else{
		for(int i=1; i<n-1; i++){
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
	
}

void List::reverse(){
	temp = listptr;
	temp = temp->next;
	listptr -> next = NULL;
	Node *temp2;
	while(temp != NULL){
		temp2 = temp->next;
		temp -> next = listptr;
		listptr = temp;
		temp = temp2;
	}
}

void List::concatnate(List I, List I2){
	I.temp = I.listptr;
	while(I.temp->next != NULL){
		I.temp = I.temp->next;
	}
	I.temp->next = I2.listptr;
}

int main(){
	int p=1,ch;
	List I;
	List I2;
	while(p==1)
	{
		cout<<"\n Enter Choice: \n1) Create \n2) Display \n3) Insert at Start \n4) Insert at End\n5) Insert in Between\n6) Deleting a Node\n7) Reverse the list\n8) Concatenate\n";
		cin>>ch;
		switch(ch){
			case 1:
				I.create();
				break;
			case 2:
				I.display();
				break;
			case 3:
				I.insertStart();
				break;
			case 4:
				I.insertEnd();
				break;
			case 5:
				I.insertInBetween();
				break;
			case 6:
				I.deleteNode();
				break;
			case 7:
				I.reverse();
				break;
			case 8:
				cout<<"Making second List"<<endl;
				I2.create();
				I.concatnate(I, I2);
				break;
			default:
			cout<<"Invalid";
		}
		cout<<"\nPRESS 1 TO CONTINUE: ";
		cin>>p;
	}
}
