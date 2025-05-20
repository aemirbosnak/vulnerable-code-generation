//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *key;
	struct node *left;
	struct node *right;
};

struct node *new_node(char *key) {
	struct node *node = malloc(sizeof(struct node));
	node->key = strdup(key);
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert(struct node **root, char *key) {
	if (*root == NULL) {
		*root = new_node(key);
	} else if (strcmp(key, (*root)->key) < 0) {
		insert(&(*root)->left, key);
	} else {
		insert(&(*root)->right, key);
	}
}

struct node *find(struct node *root, char *key) {
	if (root == NULL) {
		return NULL;
	} else if (strcmp(key, root->key) == 0) {
		return root;
	} else if (strcmp(key, root->key) < 0) {
		return find(root->left, key);
	} else {
		return find(root->right, key);
	}
}

void print_tree(struct node *root) {
	if (root == NULL) {
		return;
	}
	print_tree(root->left);
	printf("%s\n", root->key);
	print_tree(root->right);
}

int main() {
	struct node *root = NULL;
	insert(&root, "hello");
	insert(&root, "world");
	insert(&root, "!");
	print_tree(root);
	return 0;
}