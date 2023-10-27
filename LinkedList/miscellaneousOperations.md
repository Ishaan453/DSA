# Miscellaneous Operations on Linked List

## Reversing a Linked List
Reversing a singly linked list (SLL) involves changing the order of the elements in the list such that the last element becomes the first, and the first becomes the last, while maintaining the individual element's connections. This process typically requires iterative or recursive traversal of the list to rewire the pointers in the opposite direction, resulting in a reversed linked list.<br>
![](https://github.com/Ishaan453/DSA/blob/main/Images/reversing-list.gif)<br>

```cpp

void List::reverse(){
    Node *forward, *curr, *back;
    forward = listptr;
    curr = NULL;
    while(forward != NULL){
        back = curr;
        curr = forward;
        forward = forward->next;
        curr->next = back;
    }
    listptr = curr;
}

```

## Concat two Linked Lists
Concatenating is simple, we just traverse till the last node of the first Linked list and then modify its next pointer to the head of second linked list<br>
![](https://github.com/Ishaan453/DSA/blob/main/Images/concat-list.jpeg)<br>

```cpp

void List::concat(List obj){
    temp = listptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = obj.listptr;
}

```
Note: In this code, the calling object if the first List and the parameter object is second linked list.
