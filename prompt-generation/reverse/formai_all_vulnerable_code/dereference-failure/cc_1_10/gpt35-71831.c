//FormAI DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Create the structure for the binary search tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a function to add a node to the binary search tree
TreeNode* insertNode(TreeNode* tree, int newData) {
    if (tree == NULL) {
        tree = (TreeNode*) malloc(sizeof(TreeNode));
        tree->data = newData;
        tree->left = NULL;
        tree->right = NULL;
        printf("Node %d has been added.\n", newData);
    } else if (newData < tree->data) {
        tree->left = insertNode(tree->left, newData);
    } else {
        tree->right = insertNode(tree->right, newData);
    }
    return tree;
}

// Create a function to traverse the binary search tree in-order
void inOrderTraversal(TreeNode* tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->left);
        printf("%d ", tree->data);
        inOrderTraversal(tree->right);
    }
}

int main() {
    // Initialize the binary search tree
    TreeNode* root = NULL;

    // Add nodes to the binary search tree
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 15);
    root = insertNode(root, 25);

    // Traverse the binary search tree in-order
    printf("In-order traversal: ");
    inOrderTraversal(root);

    return 0;
}