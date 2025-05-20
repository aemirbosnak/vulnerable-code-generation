//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Search for a node with the given data in the binary search tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Print the binary search tree in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test the binary search tree implementation
int main() {
    Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the binary search tree in order traversal
    printf("Binary search tree in order traversal:\n");
    printTree(root);
    printf("\n");

    // Search for a node in the binary search tree
    Node* searchResult = searchNode(root, 40);
    if (searchResult!= NULL) {
        printf("Node found with data %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}