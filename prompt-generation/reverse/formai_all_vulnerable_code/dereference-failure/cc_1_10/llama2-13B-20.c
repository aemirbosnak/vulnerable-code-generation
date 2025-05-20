//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a recursive binary search
struct Node* binarySearch(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (target < root->data) {
        return binarySearch(root->left, target);
    } else if (target > root->data) {
        return binarySearch(root->right, target);
    } else {
        return root;
    }
}

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the binary search tree
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    // Test case 1: Insert 3, 5, and 7 in order
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    printTree(root);

    // Test case 2: Insert 2, 4, and 6 out of order
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    printTree(root);

    return 0;
}