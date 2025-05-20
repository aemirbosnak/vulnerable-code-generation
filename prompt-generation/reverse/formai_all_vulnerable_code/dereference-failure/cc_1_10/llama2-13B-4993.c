//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a binary search tree
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node with given data
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the tree
struct node* insert(struct node** root, int data) {
    if (!*root) {
        *root = new_node(data);
        return *root;
    }

    if (data < (*root)->data) {
        (*root)->left = insert(&(*root)->left, data);
    } else {
        (*root)->right = insert(&(*root)->right, data);
    }

    return *root;
}

// Function to search for a node in the tree
struct node* search(struct node* root, int data) {
    if (!root) {
        return NULL;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to traverse the tree
void traverse(struct node* root) {
    if (root) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // Test cases
    root = insert(&root, 5);
    root = insert(&root, 2);
    root = insert(&root, 8);
    root = insert(&root, 3);
    root = insert(&root, 1);

    // Traverse the tree
    traverse(root);

    return 0;
}