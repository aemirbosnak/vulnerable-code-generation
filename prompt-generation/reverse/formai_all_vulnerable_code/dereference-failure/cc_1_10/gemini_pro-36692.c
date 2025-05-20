//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the binary search tree
struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *new_node(char *key, int value) {
    struct node *new = malloc(sizeof(struct node));
    new->key = strdup(key);
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Insert a new node into the binary search tree
struct node *insert(struct node *root, char *key, int value) {
    if (root == NULL) {
        return new_node(key, value);
    }
    if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key, value);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert(root->right, key, value);
    }
    return root;
}

// Find a node in the binary search tree
struct node *find(struct node *root, char *key) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(key, root->key) == 0) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        return find(root->left, key);
    } else {
        return find(root->right, key);
    }
}

// Print the binary search tree in preorder
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%s: %d\n", root->key, root->value);
    preorder(root->left);
    preorder(root->right);
}

// Free the binary search tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free(root->key);
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    struct node *root = NULL;
    root = insert(root, "key1", 1);
    root = insert(root, "key2", 2);
    root = insert(root, "key3", 3);
    root = insert(root, "key4", 4);
    root = insert(root, "key5", 5);
    preorder(root);
    struct node *found = find(root, "key3");
    if (found != NULL) {
        printf("Found: %s: %d\n", found->key, found->value);
    } else {
        printf("Not found: key3\n");
    }
    free_tree(root);
    return 0;
}