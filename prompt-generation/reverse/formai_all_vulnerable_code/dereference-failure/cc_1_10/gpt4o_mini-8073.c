//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
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

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function for in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary search tree
int main() {
    Node* root = NULL; // Create an empty BST

    // Insert nodes into the BST
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the binary search tree:\n");
    inOrderTraversal(root);
    printf("\n");

    // Search for nodes in the BST
    int searchData[] = {15, 5, 20, 100}; // Values to search
    for (int i = 0; i < 4; ++i) {
        Node* result = search(root, searchData[i]);
        if (result != NULL) {
            printf("Node with data %d found in the BST.\n", searchData[i]);
        } else {
            printf("Node with data %d not found in the BST.\n", searchData[i]);
        }
    }

    // Free the memory allocated for the BST
    freeTree(root);
    return 0;
}