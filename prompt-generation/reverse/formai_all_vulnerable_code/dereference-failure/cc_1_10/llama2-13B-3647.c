//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node representing a binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new BSTNode with a given data value
struct BSTNode *newBSTNode(int data) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a recursive binary search
int recursiveBinarySearch(struct BSTNode *root, int target) {
    if (root == NULL) {
        return -1;
    }

    if (target < root->data) {
        return recursiveBinarySearch(root->left, target);
    } else if (target > root->data) {
        return recursiveBinarySearch(root->right, target);
    } else {
        return 0; // Found the target!
    }
}

// Function to insert a new node into the BST
struct BSTNode *insertBSTNode(struct BSTNode *root, int data) {
    if (root == NULL) {
        root = newBSTNode(data);
    } else if (data < root->data) {
        root->left = insertBSTNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertBSTNode(root->right, data);
    }

    return root;
}

int main() {
    struct BSTNode *root = NULL;

    // Test cases
    root = insertBSTNode(root, 5);
    root = insertBSTNode(root, 2);
    root = insertBSTNode(root, 8);
    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);

    // Perform a recursive binary search
    int target = 6;
    int result = recursiveBinarySearch(root, target);

    if (result != -1) {
        printf("Found %d at depth %d\n", target, result);
    } else {
        printf("Not found\n");
    }

    return 0;
}