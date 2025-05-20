//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int key) {
    if (root == NULL) {
        root = malloc(sizeof(node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

node *find(node *root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key == root->key) {
        return root;
    } else if (key < root->key) {
        return find(root->left, key);
    } else {
        return find(root->right, key);
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    node *found = find(root, 15);
    if (found != NULL) {
        printf("Found node with key 15\n");
    } else {
        printf("Node with key 15 not found\n");
    }

    return 0;
}