## Node Class for Linked List<br>
We create a structure node for the linked list with the necessary data variable and the next pointer. For Doubly Linked list we also need a pointer to previous node.
```cpp
class Node {
    public:
    int data;
    Node* next;
};
```

## The List Class<br>
In this class, we store the head of each object of class created and a temp variable to traversing the linked list.
```cpp
class List:public Node{
    Node *listptr, *temp;
    public:
        List(){
        listptr=NULL;
        temp=NULL;
    }
};
```

## The Main Class<br>
In the main class we can create as many objects of list class accouding to the number of Linked Lists we need.
```cpp
int main(){
    List I;
}
```
<br>

We have successfully created a **Node class**, from which we can create new nodes for our Linked List, A **List class** which will hold the head pointer of the list and an object. If we want to create _'n'_ linked lists, we can make _'n'_ ojects of the **List Class** or create an array of object.<br>

## Create() Function<br>
All the functions of the Linked List will come under the **List Class**.<br>
We will first declare the function _create()_ in the List class and then define it outside with the help of _Scope Resolution (::)_ operator.<br>

```cpp
class List:public Node{
    Node *listptr, *temp;
    public:
        List(){
        listptr=NULL;
        temp=NULL;
    }

    void create();
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

```
<br>
and now we can call the create function in the main class<br>

```cpp
int main(){
    List I;
    I.create();
}
```


