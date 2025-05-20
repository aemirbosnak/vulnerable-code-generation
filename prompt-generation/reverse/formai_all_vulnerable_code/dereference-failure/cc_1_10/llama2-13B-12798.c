//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a binary search on the tree
struct Node* binarySearch(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        return binarySearch(root->left, key);
    } else if (key > root->data) {
        return binarySearch(root->right, key);
    } else {
        return root;
    }
}

// Function to insert a new node into the tree
struct Node* insertNode(struct Node** root_ref, int key) {
    struct Node* root = *root_ref;

    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->data) {
        root->left = insertNode(&root->left, key);
    } else {
        root->right = insertNode(&root->right, key);
    }

    return root;
}

// Example usage of the binary search function
int main() {
    struct Node* root = NULL;

    root = insertNode(&root, 10);
    root = insertNode(&root, 5);
    root = insertNode(&root, 8);
    root = insertNode(&root, 3);
    root = insertNode(&root, 6);
    root = insertNode(&root, 12);

    struct Node* found = binarySearch(root, 8);

    if (found != NULL) {
        printf("Found %d at index %d\n", found->data, found->left == NULL ? 0 : 1);
    } else {
        printf("Not found\n");
    }

    return 0;
}