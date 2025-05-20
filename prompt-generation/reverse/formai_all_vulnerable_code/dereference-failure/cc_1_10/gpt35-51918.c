//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

struct node *newnode(int item){
	struct node *temp= (struct node *)malloc(sizeof(struct node));
	temp->data= item;
	temp->left= temp->right= NULL;
	return temp;
}

struct node *insert(struct node *node, int data){
	if(node==NULL)
		return newnode(data);

	if(data < node->data)
		node->left= insert(node->left, data);
	else if(data > node->data)
		node->right= insert(node->right, data);

	return node;
}

struct node *search(struct node *root, int key){
	if(root==NULL || root->data == key)
		return root;

	if(key < root->data)
		return search(root->left,key);
 
	else
		return search(root->right,key);
}


int main(){

	struct node *root= NULL;
	root= insert(root, 25);
	insert(root, 15);
	insert(root, 30);
	insert(root, 10);
	insert(root, 22);
	insert(root, 28);
	insert(root, 35);

	printf("Inorder Traversal of the BST tree: \n");
	inorder(root);

	int key= 22;
	struct node *result= search(root, key);
	if(result!=NULL)
		printf("\n Key %d is present in the BST tree. \n", key);
	else
		printf("\n Key %d is not present in the BST tree. \n", key);

	return 0;
}