//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to insert data into the binary tree
struct Node* insert(struct Node* root, int data) {
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

// Recursive function to traverse the tree in-order and print the data
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Recursive function to count nodes in the binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Recursive function to find the sum of all values in the binary tree
int sumNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Recursive function to find the maximum value in the binary tree
int findMax(struct Node* root) {
    if (root == NULL) {
        return -1; // Assuming all data is non-negative 
    }
    
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    
    return max;
}

// Recursive function to find the minimum value in the binary tree
int findMin(struct Node* root) {
    if (root == NULL) {
        return -1; // Assuming all data is non-negative 
    }
    
    int min = root->data;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    
    if (leftMin < min && leftMin != -1) {
        min = leftMin;
    }
    if (rightMin < min && rightMin != -1) {
        min = rightMin;
    }
    
    return min;
}

// Main function to run the program
int main() {
    struct Node* root = NULL;
    
    // Sample data for the binary tree
    int data[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(data) / sizeof(data[0]);
    
    // Inserting data into the binary tree
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }
    
    // In-order traversal
    printf("In-order traversal of the binary tree:\n");
    inOrder(root);
    printf("\n");

    // Count nodes
    printf("Total nodes in the binary tree: %d\n", countNodes(root));

    // Sum of all nodes
    printf("Sum of all nodes in the binary tree: %d\n", sumNodes(root));

    // Maximum value
    printf("Maximum value in the binary tree: %d\n", findMax(root));

    // Minimum value
    printf("Minimum value in the binary tree: %d\n", findMin(root));

    // Free memory before exiting
    free(root);
    
    return 0;
}