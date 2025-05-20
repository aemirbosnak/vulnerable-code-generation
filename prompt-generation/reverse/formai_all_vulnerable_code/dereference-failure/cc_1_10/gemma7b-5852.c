//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Recursive search function
struct node* search(struct node* node, int target) {
    // If the node is NULL, the target is not found
    if (node == NULL) {
        return NULL;
    }

    // If the target is found, the node is returned
    if (node->data == target) {
        return node;
    }

    // If the target is less than the node's data, the left subtree is searched
    else if (node->data > target) {
        return search(node->left, target);
    }

    // Otherwise, the right subtree is searched
    else {
        return search(node->right, target);
    }
}

int main() {
    // Create a binary tree
    struct node* root = malloc(sizeof(struct node));
    root->data = 20;
    root->left = malloc(sizeof(struct node));
    root->left->data = 10;
    root->right = malloc(sizeof(struct node));
    root->right->data = 30;

    // Search for a target in the binary tree
    struct node* result = search(root, 15);

    // If the target is found, print its data
    if (result) {
        printf("Target found: %d\n", result->data);
    } else {
        printf("Target not found.\n");
    }

    return 0;
}