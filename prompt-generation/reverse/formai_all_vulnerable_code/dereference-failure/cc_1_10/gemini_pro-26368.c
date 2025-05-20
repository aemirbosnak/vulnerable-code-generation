//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *create_node(int data) {
	struct node *node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct node *insert_node(struct node *root, int data) {
	if (root == NULL) {
		return create_node(data);
	} else if (data < root->data) {
		root->left = insert_node(root->left, data);
	} else if (data > root->data) {
		root->right = insert_node(root->right, data);
	}
	return root;
}

struct node *search_node(struct node *root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (data == root->data) {
		return root;
	} else if (data < root->data) {
		return search_node(root->left, data);
	} else if (data > root->data) {
		return search_node(root->right, data);
	}
	return NULL;
}

void print_tree(struct node *root) {
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data);
	print_tree(root->left);
	print_tree(root->right);
}

int main() {
	struct node *root = NULL;
	for (int i = 0; i < N; i++) {
		root = insert_node(root, rand() % 100);
	}
	print_tree(root);
	for (int i = 0; i < N; i++) {
		struct node *node = search_node(root, rand() % 100);
		if (node != NULL) {
			printf("Found %d\n", node->data);
		} else {
			printf("Not found\n");
		}
	}
	return 0;
}