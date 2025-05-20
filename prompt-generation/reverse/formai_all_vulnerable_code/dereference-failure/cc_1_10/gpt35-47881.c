//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Defining the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a new node into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a data in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to traverse the tree in-order
void traverseInOrder(Node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->data);
        traverseInOrder(root->right);
    }
}

int main() {
    printf("Welcome to the Cyberpunk Binary Search Tree!\n");
    printf("--------------------------------------------\n");

    // Creating the root node
    Node* root = NULL;

    // Inserting nodes
    root = insert(root, 10);
    insert(root, 8);
    insert(root, 13);
    insert(root, 6);
    insert(root, 9);
    insert(root, 11);
    insert(root, 15);

    // Traversing the tree in-order
    printf("\nIn-Order Traversal: ");
    traverseInOrder(root);

    // Searching for a data in the tree
    printf("\n\nSearching for data 9...");
    Node* result = search(root, 9);
    if (result != NULL) {
        printf("\nData 9 found!");
    } else {
        printf("\nData 9 not found.");
    }

    return 0;
}