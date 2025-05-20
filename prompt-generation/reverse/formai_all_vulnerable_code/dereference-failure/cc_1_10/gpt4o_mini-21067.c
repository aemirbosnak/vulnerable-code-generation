//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the binary tree
Node* insert(Node* root, int data) {
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

// Recursive function to find the maximum value in the binary tree
int findMax(Node* root) {
    if (root == NULL) {
        return -1; // Represents an empty tree
    }
    if (root->right != NULL) {
        return findMax(root->right); // Explore the right subtree
    }
    return root->data; // Current node is the maximum
}

// Function to display the binary tree in-order (sorted)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to free the binary tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the data mining approach
int main() {
    Node* root = NULL;
    int dataPoints[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(dataPoints) / sizeof(dataPoints[0]);

    // Insert data points into the binary tree
    for (int i = 0; i < n; i++) {
        root = insert(root, dataPoints[i]);
    }

    printf("In-order traversal of the binary tree:\n");
    inOrder(root);
    printf("\n");

    // Finding the maximum value in the binary tree
    int maxValue = findMax(root);
    if (maxValue != -1) {
        printf("The maximum value in the binary tree is: %d\n", maxValue);
    } else {
        printf("The binary tree is empty.\n");
    }

    // Free the allocated memory
    freeTree(root);
    return 0;
}