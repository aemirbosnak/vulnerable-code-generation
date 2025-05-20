//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node with a given value and return a pointer to it
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
void insertNode(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }
    if (value < (*root)->value) {
        insertNode(&((*root)->left), value);
    } else if (value > (*root)->value) {
        insertNode(&((*root)->right), value);
    }
}

// Function to perform an inorder traversal of the binary tree and print its values
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

int main() {
    // Initialize the binary tree with some values
    TreeNode* root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 12);
    insertNode(&root, 20);

    // Perform an inorder traversal of the binary tree and print its values
    printf("Inorder traversal:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}