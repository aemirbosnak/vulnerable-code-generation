//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a node structure for a binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
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

// Function to perform inorder traversal and count nodes
void inorder(Node* root, int* count) {
    if (root != NULL) {
        inorder(root->left, count);
        (*count)++;
        inorder(root->right, count);
    }
}

// Function to calculate the height of the binary tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return fmax(leftHeight, rightHeight) + 1;
}

// Function to visualize the binary tree
void visualizeTree(Node* root, int space) {
    if (root == NULL) return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    visualizeTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    visualizeTree(root->left, space);
}

// Function to free the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary tree
int main() {
    Node* root = NULL;
    int data[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(data)/sizeof(data[0]);

    // Insert nodes into the binary tree
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // Visualize the binary tree
    printf("Visual representation of the binary search tree:\n");
    visualizeTree(root, 0);

    // Count nodes
    int count = 0;
    inorder(root, &count);
    printf("\nTotal number of nodes in the tree: %d\n", count);

    // Calculate and print the height
    printf("Height of the tree: %d\n", height(root));

    // Free the allocated memory
    freeTree(root);
    return 0;
}