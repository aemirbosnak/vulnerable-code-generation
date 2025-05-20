//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Define a function to create a new tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to insert a node into the tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
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

// Define a function to traverse the tree
void traverse(struct TreeNode* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into the tree
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);

    // Traverse the tree
    traverse(root);

    return 0;
}