//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Recursive function to print the tree
void printTree(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    // Print the current node
    printf("%d ", root->data);

    // Recursively print the left subtree
    printTree(root->left);

    // Recursively print the right subtree
    printTree(root->right);

    return;
}

int main() {
    // Create a tree with the following structure:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->data = 3;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->data = 4;
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->data = 5;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->data = 6;

    printTree(root);

    return 0;
}