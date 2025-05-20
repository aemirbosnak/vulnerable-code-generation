//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
TreeNode* insert(TreeNode *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to do inorder traversal of the binary tree
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to visualize the binary tree
void visualize(TreeNode *root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    visualize(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    visualize(root->left, space);
}

// Function to free the binary tree
void freeTree(TreeNode *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to drive the program
int main() {
    TreeNode *root = NULL;
    int numValues = 10;
    int values[] = {50, 30, 20, 40, 70, 60, 80, 10, 90, 25};

    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal of the binary tree:\n");
    inorder(root);
    printf("\n\n");

    printf("Visual representation of the binary tree:\n");
    visualize(root, 0);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);
    return 0;
}