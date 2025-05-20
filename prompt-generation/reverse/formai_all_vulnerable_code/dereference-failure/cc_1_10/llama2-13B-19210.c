//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Define a function to create a new tree node
struct TreeNode *newNode(int data) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to traverse the tree in a recursive manner
void traverse(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    traverse(root->left);

    // Traverse the right subtree
    traverse(root->right);
}

int main() {
    // Create a new tree node with data 1
    struct TreeNode *root = newNode(1);

    // Create two new tree nodes with data 2 and 3
    struct TreeNode *node2 = newNode(2);
    struct TreeNode *node3 = newNode(3);

    // Add the nodes to the tree
    root->left = node2;
    root->right = node3;

    // Traverse the tree
    traverse(root);

    return 0;
}