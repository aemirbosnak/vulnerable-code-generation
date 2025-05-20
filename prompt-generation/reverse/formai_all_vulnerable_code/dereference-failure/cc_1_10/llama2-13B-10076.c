//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a binary search on the tree
int binarySearch(struct Node* root, int key) {
    if (root == NULL) {
        return -1;
    }

    if (key < root->data) {
        return binarySearch(root->left, key);
    } else if (key > root->data) {
        return binarySearch(root->right, key);
    } else {
        return 0;
    }
}

// Example usage of the binary search function
int main() {
    struct Node* root = NULL;

    // Create a binary search tree with the following nodes
    root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int key = 4;
    int result = binarySearch(root, key);

    if (result == 0) {
        printf("The key %d is found in the tree\n", key);
    } else {
        printf("The key %d is not found in the tree\n", key);
    }

    return 0;
}