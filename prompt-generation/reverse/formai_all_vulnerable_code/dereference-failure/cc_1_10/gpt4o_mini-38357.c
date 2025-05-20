//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Recursive insertion logic
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root; // return updated root
}

// Function to search a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    // Recursive search logic
    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left); // Visit left subtree
        printf("%d ", root->data);     // Visit node
        inOrderTraversal(root->right); // Visit right subtree
    }
}

// Function to free the allocated memory of the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;

    // Enthusiastic insertion of nodes into the BST!
    printf("Welcome to the Amazing Binary Search Tree Program!\n");
    
    int values[] = {7, 3, 9, 1, 4, 8, 10};
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        printf("Inserting %d into the Binary Search Tree...\n", values[i]);
        root = insert(root, values[i]);
    }

    printf("\nIn-order Traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Searching for values in the BST
    int searchValues[] = {4, 2, 8, 11};
    for (int i = 0; i < sizeof(searchValues)/sizeof(searchValues[0]); i++) {
        struct Node* result = search(root, searchValues[i]);
        if (result != NULL) {
            printf("Value %d found in the BST!\n", searchValues[i]);
        } else {
            printf("Value %d not found in the BST!\n", searchValues[i]);
        }
    }

    // Free up the allocated memory
    freeTree(root);
    printf("Thank you for using the Binary Search Tree Program! Goodbye!\n");

    return 0;
}