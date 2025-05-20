//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to visualize the binary tree
void printTree(struct TreeNode* root, int space) {
    int COUNT = 10; // Space between nodes
    if (root == NULL) {
        return;
    }
    space += COUNT;

    printTree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Function to free the memory used by the tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int numElements = 10; // Change this for more or fewer nodes
    srand(time(0)); // Seed for random number generation

    // Generate random values to insert into the binary tree
    for (int i = 0; i < numElements; i++) {
        int randomValue = rand() % 100; // Random values between 0 and 99
        printf("Inserting: %d\n", randomValue);
        root = insert(root, randomValue);
    }

    // Visualize the tree
    printf("\nBinary Tree Visualization:\n");
    printTree(root, 0);

    // Free the allocated memory
    freeTree(root);
    return 0;
}