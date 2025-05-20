//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include<stdio.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int val)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct node* insert(struct node* root, int val)
{
	if(root == NULL)
		return newNode(val);

	if(val < root->data)
		root->left = insert(root->left, val);
	else if(val > root->data)
		root->right = insert(root->right, val);

	return root;
}

void inorder(struct node* root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void printTree(struct node* root)
{
	if(root == NULL)
		return;

	printf("Inorder traversal of the tree is :-\n");
	inorder(root);
}

void search(struct node* root, int val)
{
	if(root == NULL)
		return;

	if(val == root->data)
		printf("Element found at %d\n", root->data);
	else if(val < root->data)
		search(root->left, val);
	else
		search(root->right, val);
}

int main()
{
	struct node* root = NULL;

	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 4);
	root = insert(root, 22);
	root = insert(root, 2);
	root = insert(root, 10);
	root = insert(root, 6);
	root = insert(root, 14);
	root = insert(root, 18);
	root = insert(root, 12);
	root = insert(root, 16);
	root = insert(root, 24);
	root = insert(root, 26);
	root = insert(root, 28);
	root = insert(root, 30);
	root = insert(root, 32);
	root = insert(root, 34);

	printf("Given Binary Search Tree is :-\n");
	printTree(root);

	search(root, 8);
	search(root, 28);
	search(root, 32);

	return 0;
}