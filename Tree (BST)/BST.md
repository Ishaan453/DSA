# Creating A Binary Search Tree
![](https://github.com/Ishaan453/DSA/blob/main/Images/searchBinarySearchTree.png)<br>

The format of creating a node for a tree is almost same as DLL, just instead of *next and *prev, we have *left and *right, potraying left and right child of the node respectively.<br>
```cpp

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

```
<br>

After creating the Node class, we create a tree class, which stores the location of root of the tree and with help of tree class, we perform various operations on the tree like searching, traversals etc.
```cpp

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

```
<br>
you can see the functions in the tree class, which we will be performing on the tree.

## create()
For the create function, we take input of each node one by one and arrange them in such a order that it becomes a BST. It means when new node is added, we start from the root, check if its less than or greater than the root and then decide if it should go left or right, this goes on till we get a node with NULL child so we can add the new node there.
```cpp

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

```
# Tree Traversals
![](https://github.com/Ishaan453/DSA/blob/main/Images/tree_traversal.png)<br>

For performing tree traversals, we will require a stack, so we create one.
```cpp

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

```

## Inorder Traversal
Inorder traversal means<br>
1)  Traverse the left subtree, i.e., call Inorder(left->subtree)<br>
2)  Visit the root.<br>
3)  Traverse the right subtree, i.e., call Inorder(right->subtree)<br>

```cpp

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

```

## PreOrder Traversal
PreOrder traversal means<br>
1)  Visit the root.<br>
2)  Traverse the left subtree, i.e., call Preorder(left->subtree)<br>
3)  Traverse the right subtree, i.e., call Preorder(right->subtree)<br>

```cpp

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

```

## PostOrder Traversal
PostOrder Traversal means<br>
1)  Traverse the left subtree, i.e., call Postorder(left->subtree)<br>
2)  Traverse the right subtree, i.e., call Postorder(right->subtree)<br>
3)  Visit the root<br>

```cpp

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

```

## Searching
BST is a great data structure for searching elements as it provides us the time complexity of O(log n) because we exactly know which side we should go from the node. We start from the root, if element if larger, we go right, if element is smaller, we go left. This goes on till we reach a NULL pointer or we found the element.

```cpp

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

```

## Deleting Node
![](https://github.com/Ishaan453/DSA/blob/main/Images/deletion-in-binary-search-tree3.png)
Deletion of a node in binary tree can be complex.
1)  Case 1: Deleting a leaf node: Traverse till the selected node, check if its left and right pointer are NULL, if yes, make the pointer of previous node null and delete the leaf node.<br>
2)  Case 2: Deleting Node with only one branch: Traverse till the selected node, check if its left or right pointer are NULL, if one of them is not NULL, just attach the next node of the deleting node to its parent<br>
3)  Case 3:  Node with Both branches: The node which is to be deleted, is replaced with its in-order successor or predecessor recursively until the node value (to be deleted) is placed on the leaf of the tree. After the procedure, replace the node with NULL and free the allocated space.
OR
3)  Case 3: Node with Both Branches: We already know that the right side is greater than every element on the left side of the node. So, We take the whole right branch of the Node to be deleted and place it to the right of the rightmost node of the left brance of the node to be deleted.<br>

Case 3 has two types, therefore we have 2 different code for deletion<br>
First<br>
```cpp

void tree::deleteNode(int n){
	Node *temp = root, *parent = NULL;
	while(temp != NULL){
		if(temp->data == n){
			break;
		}
		else{
			if(temp->data > n){
				parent = temp;
				temp = temp->left;
			}
			else{
				parent = temp;
				temp = temp->right;
			}
		}
	}
	if(temp == NULL){
		cout<<"Data not found"<<endl;
		return;
	}

	if(temp->left == NULL && temp->right == NULL){
		if(parent == NULL){
			root == NULL;
		}
		else{
			if(parent -> left == temp){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
		}
		delete temp;
		return;
	}

	if(temp->left == NULL && temp->right != NULL){
		if(parent == NULL){
			root = temp->right;
			delete temp;
		}
		else if(parent->left == temp){
			parent->left = temp->right;
		}
		else{
			parent->right = temp->right;
		}
		delete temp;
		return;
	}

	if(temp->left != NULL && temp->right == NULL){
		if(parent == NULL){
			root = temp->left;
			delete temp;
		}
		else if(parent->left == temp){
			parent->left = temp->left;
		}
		else{
			parent->right = temp->left;
		}
		delete temp;
		return;
	}

	if(temp->left != NULL && temp->right != NULL){
		Node *x, *y = NULL;
		x = temp->right;
		while(x->left != NULL){
			y = x;
			x = x->left;
		}
		int t = temp->data;
		temp->data = x->data;
		x->data = t;
		delete x;
		if(y != NULL){
			if(x->right != NULL){
				y->left = x->right;
			}
			else{
				y->left = NULL;
			}
		}
		else{
			temp->right = x->right;
		}
		delete x;
	}


}

```

Second<br>
```cpp

void tree::deleteNode(int n){
	Node *temp = root, *parent = NULL;
	while(temp != NULL){
		if(temp->data == n){
			break;
		}
		else{
			if(temp->data > n){
				parent = temp;
				temp = temp->left;
			}
			else{
				parent = temp;
				temp = temp->right;
			}
		}
	}
	if(temp == NULL){
		cout<<"Data not found"<<endl;
		return;
	}

	if(temp->left == NULL && temp->right == NULL){
		if(parent == NULL){
			root == NULL;
		}
		else{
			if(parent -> left == temp){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
		}
		delete temp;
		return;
	}

	if(temp->left == NULL && temp->right != NULL){
		if(parent == NULL){
			root = temp->right;
			delete temp;
		}
		else if(parent->left == temp){
			parent->left = temp->right;
		}
		else{
			parent->right = temp->right;
		}
		delete temp;
		return;
	}

	if(temp->left != NULL && temp->right == NULL){
		if(parent == NULL){
			root = temp->left;
			delete temp;
		}
		else if(parent->left == temp){
			parent->left = temp->left;
		}
		else{
			parent->right = temp->left;
		}
		delete temp;
		return;
	}

	if(temp->left != NULL && temp->right != NULL){
		Node *x, *y;
		if(parent == NULL){
			root = temp->left;
			x = temp->left;
			y = temp->right;

			while(x->right != NULL){
				x = x->right;
			}
			x->right = y;
			delete temp;
			return;
		}
		else if(parent->left == temp){
			x = temp->left;
			y = temp->right;
			parent->left = x;

			while(x->right != NULL){
				x = x->right;
			}
			x->right = y;
			delete temp;
			return;
		}
		else{
			x = temp->left;
			y = temp->right;
			parent->right = x;

			while(x->right != NULL){
				x = x->right;
			}
			x->right = y;
			delete temp;
			return;
		}
	}

}

```



