//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A utility function to create a new binary tree node
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a node into a BST
struct node *insert(struct node *node, int data) {
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// A utility function to find the maximum depth of a BST
int maxDepth(struct node *node) {
    if (node == NULL)
        return 0;

    int left_depth = maxDepth(node->left);
    int right_depth = maxDepth(node->right);

    return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);
}

// A utility function to print the BST in preorder traversal
void preorder(struct node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Driver program to test the above functions
int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Find the maximum depth of the BST
    int max_depth = maxDepth(root);

    // Print the BST in preorder traversal
    preorder(root);

    return 0;
}