//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* create_node(int data) {
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

struct node* insert_node(struct node *root, int data) {
	if (root == NULL)
		return create_node(data);
	if (data < root->data)
		root->left = insert_node(root->left, data);
	else
		root->right = insert_node(root->right, data);
	return root;
}

struct node* search_node(struct node *root, int data) {
	if (root == NULL)
		return NULL;
	if (data == root->data)
		return root;
	if (data < root->data)
		return search_node(root->left, data);
	else
		return search_node(root->right, data);
}

void inorder_traversal(struct node *root) {
	if (root == NULL)
		return;
	inorder_traversal(root->left);
	printf("%d ", root->data);
	inorder_traversal(root->right);
}

void preorder_traversal(struct node *root) {
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void postorder_traversal(struct node *root) {
	if (root == NULL)
		return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ", root->data);
}

void delete_node(struct node *root, int data) {
	if (root == NULL)
		return;
	if (data == root->data) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return;
		}
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			root = temp;
			return;
		}
		if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			root = temp;
			return;
		}
		struct node *temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;
		root->data = temp->data;
		delete_node(root->right, temp->data);
		return;
	}
	if (data < root->data)
		delete_node(root->left, data);
	else
		delete_node(root->right, data);
}

int main() {
	struct node *root = NULL;
	root = insert_node(root, 10);
	root = insert_node(root, 5);
	root = insert_node(root, 15);
	root = insert_node(root, 2);
	root = insert_node(root, 7);
	root = insert_node(root, 12);
	root = insert_node(root, 20);

	printf("Inorder traversal: ");
	inorder_traversal(root);
	printf("\n");

	printf("Preorder traversal: ");
	preorder_traversal(root);
	printf("\n");

	printf("Postorder traversal: ");
	postorder_traversal(root);
	printf("\n");

	struct node *found_node = search_node(root, 15);
	if (found_node == NULL)
		printf("Node not found\n");
	else
		printf("Node found: %d\n", found_node->data);

	delete_node(root, 15);
	printf("Inorder traversal after deleting 15: ");
	inorder_traversal(root);
	printf("\n");

	return 0;
}