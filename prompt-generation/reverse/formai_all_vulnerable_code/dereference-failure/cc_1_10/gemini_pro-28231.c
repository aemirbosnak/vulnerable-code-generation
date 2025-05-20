//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

// A binary tree node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Insert a node into a binary search tree
node* insert(node *root, int data) {
    if (root == NULL) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Print a binary search tree in order
void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Free a binary search tree
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Main function
int main() {
    // Create a binary search tree
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree in order
    inorder(root);

    // Free the binary search tree
    free_tree(root);

    return 0;
}