# Same Operations on CLL and DLL
## CLL

```cpp

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
    void deleteInBetween();
    void deleteStart();
    void deleteEnd();
    void concat(List obj);
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
        newnode->next = listptr;

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
    temp = listptr->next;
    cout<<listptr->data<<"->";
    while(temp != listptr){
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
    temp = listptr;
    while(temp->next != listptr){
        temp = temp->next;
    }

    temp->next = newnode;
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

    while(temp->next != listptr){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = listptr;
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

void List::deleteInBetween(){
    int n;
    temp = listptr;
    Node *temp2;
    cout<<"Enter position of node to be deleted"<<endl;
    cin>>n;
    for(int i=1; i<n-1; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void List::deleteStart(){
    temp = listptr;
    while(temp->next != listptr){
        temp = temp->next;
    }
    listptr = listptr->next;
    delete(temp->next);
    temp->next = listptr;
}

void List::deleteEnd(){
    temp = listptr;
    Node *temp2;
    while(temp->next->next!= listptr){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = listptr;
    delete temp2;
}

void List::reverse(){
    if (listptr == NULL) {
        cout << "List is empty.";
        return;
    }
    temp = listptr;
    while(temp->next != listptr){
        temp = temp->next;
    }

    Node* prevNode = temp;
    Node* current = listptr;
    Node* nextNode;

    do {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    } while (current != listptr);

    listptr = prevNode;
}

void List::concat(List obj){
    temp = listptr->next;
    while(temp->next != listptr){
        temp = temp->next;
    }
    obj.temp = obj.listptr;
    while(obj.temp->next != obj.listptr){
        obj.temp = obj.temp->next;
    }
    temp->next = obj.listptr;
    obj.temp->next = listptr;
}

int main(){
    int p=1,ch;
    List I, L;
    while(p==1)
    {
        cout<<"\n Enter Choice: \n1) Create \t\t2) Display \t\t3) Insert at Start \t4) Insert at End\t5) Insert in Between\n6) Deleting Start\t7) Deleting End\t\t8) Deleting in Between \t9) Reversing \t\t10) Concatenating\n";
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
                I.deleteStart();
                break;
            case 7:
                I.deleteEnd();
                break;
            case 8:
                I.deleteInBetween();
                break;
            case 9:
                I.reverse();
                break;
            case 10:
                cout<<"Create a second Linked List"<<endl;
                L.create();
                cout<<"concatenating the two linked lists"<<endl;
                I.concat(L);
                cout<<"Concatenation successful"<<endl;
                break;
            default:
                cout<<"Invalid";
        }
        cout<<"\nPRESS 1 TO CONTINUE: ";
        cin>>p;
    }
}

```

## DLL
```cpp

#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

class List:public Node{
    Node *listptr, *temp;

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
    void deleteInBetween();
    void deleteStart();
    void deleteEnd();
    void reverse();
    void concat(List obj);
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
        newnode->prev = NULL;

        if(listptr==NULL){
            listptr = newnode;
            temp = newnode;
        }

        else{
            temp->next = newnode;
            newnode->prev = newnode;
            temp = newnode;
        }
    }
}


void List::display(){
    temp = listptr;

    cout<<"NULL<-->";
    while(temp != NULL){
        cout<<temp->data<<"<-->";
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
    newnode->prev = NULL;

    newnode->next = listptr;
    listptr->prev = newnode;
    listptr = newnode;
}

void List::insertEnd(){
    int x;
    Node* newnode = new Node;

    cout<<"\nEnter Data: ";
    cin>>x;
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp = listptr;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
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
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    temp->next = newnode;

}

void List::deleteInBetween(){
    int n;
    temp = listptr;
    Node *temp2;
    cout<<"Enter position of node to be deleted"<<endl;
    cin>>n;
    for(int i=1; i<n-1; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    delete temp2;
}

void List::deleteStart(){
    temp = listptr;
    listptr = listptr->next;
    listptr->prev = NULL;
    delete temp;
}

void List::deleteEnd(){
    temp = listptr;
    Node *temp2;
    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = NULL;
    delete temp2;
}

void List::concat(List obj){
    temp = listptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = obj.listptr;
    obj.listptr = temp;
}

int main(){
    int p=1,ch;
    List I, L;
    while(p==1)
    {
        cout<<"\n Enter Choice: \n1) Create \t\t2) Display \t\t3) Insert at Start \t4) Insert at End\t5) Insert in Between\n6) Deleting Start\t7) Deleting End\t\t8) Deleting in Between \t9) Concatenating\n";
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
                I.deleteStart();
                break;
            case 7:
                I.deleteEnd();
                break;
            case 8:
                I.deleteInBetween();
                break;
            case 9:
                cout<<"Create a second Linked List"<<endl;
                L.create();
                cout<<"concatenating the two linked lists"<<endl;
                I.concat(L);
                cout<<"Concatenation successful"<<endl;
                break;
            default:
                cout<<"Invalid";
        }
        cout<<"\nPRESS 1 TO CONTINUE: ";
        cin>>p;
    }
}

```
