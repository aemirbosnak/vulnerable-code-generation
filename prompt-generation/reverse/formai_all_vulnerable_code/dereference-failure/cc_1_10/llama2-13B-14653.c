//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Function to create a new node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to traverse the tree
void traverse(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverse(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    traverse(root->right);
}

// Function to build a binary tree
struct TreeNode* buildTree(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct TreeNode* root = newNode(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

int main() {
    int arr[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = buildTree(arr, 0, n - 1);
    traverse(root);

    return 0;
}