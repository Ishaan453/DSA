# Inserting an element in a Linked List.

### Inserting an Element in Start of Linked List.
Given a head pointer _listptr_, we can add a new node in start of linked list by first creating a link between the new node and the first element of the linked list. After the link is created, we update our head pointer _listptr_ to point to the new node.<br>
![image info](https://github.com/Ishaan453/DSA/blob/main/Images/inserting-start.png)<br>

```cpp

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

```

### Inserting an Element at the end of Linked List.
To insert at the end of linked list, we first create a new node and traverse the list till the last node. After reaching the last node we create a link between the last node and the new node.<br>
![image info](https://github.com/Ishaan453/DSA/blob/main/Images/inserting-end.png)<br>

```cpp

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

```

### Inserting in between.
For inserting in between, we need 2 things, a Head Pointer and the position at which element should be inserted. We will input the position ' _n_ ' from the user. First we need to check if the position exists in the list or not. If not, Terminate the process, if yes then we traverse the linked list till ' _(n-1)<sup>th</sup>_ ' node of the linked list. We will create a link between the newnode and the node present at current the ' _n<sup>th</sup>_ ' position of the list. Then we will create the link between the ' _(n-1)<sup>th</sup>_ ' and the new node. this way our new ' _n<supth</sup>_ ' term will be our new node.<br>
![image info](https://github.com/Ishaan453/DSA/blob/main/Images/inserting-between.png)<br>

*Note: We assume our Liked List starts from index 0.

```cpp

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

    for(int i=0; i<n-1; i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

}

```
