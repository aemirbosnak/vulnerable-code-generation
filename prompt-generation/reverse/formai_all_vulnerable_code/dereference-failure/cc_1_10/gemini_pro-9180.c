//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct bnode {
    int data;
    struct bnode *left;
    struct bnode *right;
};

struct bnode* create_node(int data) {
    struct bnode *node = (struct bnode*)malloc(sizeof(struct bnode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bnode* insert(struct bnode *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct bnode* search(struct bnode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

int main() {
    struct bnode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    int data = 7;

    struct bnode *found = search(root, data);
    if (found != NULL) {
        printf("Found %d in the binary search tree.\n", data);
    } else {
        printf("Could not find %d in the binary search tree.\n", data);
    }

    return 0;
}