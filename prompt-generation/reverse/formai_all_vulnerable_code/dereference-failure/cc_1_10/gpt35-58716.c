//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct binaryTreeNode {
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

// Create a new node for the binary tree
struct binaryTreeNode *newNode(int value) {
    struct binaryTreeNode *node = (struct binaryTreeNode*) malloc(sizeof(struct binaryTreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Insert a node in the binary tree
struct binaryTreeNode *insertBST(struct binaryTreeNode *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->data) {
        root->left  = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

// Search a node in the binary tree
struct binaryTreeNode *searchBST(struct binaryTreeNode *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (root->data < value) {
        return searchBST(root->right, value);
    }

    return searchBST(root->left, value);
}

// Traverse the binary tree in in-order manner
void inorderTraversal(struct binaryTreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct binaryTreeNode* root = NULL;

    // Insert nodes in the binary tree
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    // Search nodes in the binary tree
    struct binaryTreeNode *searchNode = searchBST(root, 20);
    printf("Searched Value: %d\n", searchNode->data);
    searchNode = searchBST(root, 60);
    printf("Searched Value: %d\n", searchNode->data);

    // Traverse the binary tree
    inorderTraversal(root);

    return 0;
}