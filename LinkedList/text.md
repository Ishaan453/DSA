**Node Class for Linked List**
We create a structure node for the linked list with the necessary data variable and the next pointer. For Doubly Linked list we also need a pointer to previous node.
```cpp
struct Node {
    int data;
    Node* next;
};
```

**The List Class**
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

**The Main Class**
In the main class we can create as many objects of list class accouding to the number of Linked Lists we need.
```cpp
int main(){
    List I;
}
```