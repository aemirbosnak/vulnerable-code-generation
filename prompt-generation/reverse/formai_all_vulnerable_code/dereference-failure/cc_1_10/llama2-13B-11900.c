//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Define a function to create a new tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to traverse the tree and free memory
void traverseAndFree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Recursively traverse the left subtree
    traverseAndFree(root->left);

    // Print the current node's data
    printf("%d ", root->data);

    // Recursively traverse the right subtree
    traverseAndFree(root->right);

    // Free the current node's memory
    free(root);
}

int main() {
    // Create the root node
    struct TreeNode* root = newNode(10);

    // Create the left subtree
    root->left = newNode(5);

    // Create the right subtree
    root->right = newNode(15);

    // Traverse and free the tree
    traverseAndFree(root);

    return 0;
}