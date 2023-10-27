# Deleting Element in a Linked List

## Deleting from Begining
Deleting a Node from the begining is simple, we just have to point the head variable to next node of linked list and delete the first node.<br>

![image info](https://github.com/Ishaan453/DSA/blob/main/Images/deletion-in-singly-linked-list-at-beginning.png)<br>
```cpp

void List::deleteStart(){
    temp = listptr;
    listptr = listptr->next;
    delete temp;
}

```

## Deleting from End
We just traverse the linked list till the second last node and delete the last node using next pointer from second last node<br>
![image info](https://github.com/Ishaan453/DSA/blob/main/Images/deleting-a-node-from-the-last.png)<br>

```cpp

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

```

## Deleting from between
Suppose we want to delete n<sup>tn</sup> node from the Linked List. We traverst till the (n-1)<sup>th</sup> node and then we modify the next pointer on the (n-1)<sup>th</sup> node to skip the nth node, effectively removing it from the list.<br>
![Image info](https://github.com/Ishaan453/DSA/blob/main/Images/deletion-from-between.png)<br>
```cpp

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

```
