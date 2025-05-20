//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the binary tree node structure
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node with a given value
TreeNode *newNode(int value) {
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the binary search tree
TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to print the binary search tree
void printTree(TreeNode *root, int level) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", root->value);
    printTree(root->left, level + 1);
}

int main() {
    // Create an empty binary search tree
    TreeNode *root = NULL;

    // Insert some nodes into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 2);

    // Print the binary search tree
    printTree(root, 0);

    return 0;
}