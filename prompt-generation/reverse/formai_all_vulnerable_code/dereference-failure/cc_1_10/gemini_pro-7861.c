//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A utility function to create a new BST node
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a new node with the given key in BST
struct node *insert(struct node *node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// A utility function to print the preorder traversal of the BST
void preorder(struct node *node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Driver program to test the above functions
int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the preorder traversal of the BST
    preorder(root);

    return 0;
}