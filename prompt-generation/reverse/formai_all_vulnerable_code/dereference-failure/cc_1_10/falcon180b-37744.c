//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        root = createNode(value);
        return root;
    }

    // Otherwise, traverse the tree to find the correct location for the new node
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the binary search tree
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to print the binary search tree in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test the binary search tree operations
int main() {
    Node* root = NULL;

    // Insert some values into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    // Print the tree in order traversal
    printf("Binary search tree in order traversal:\n");
    printTree(root);

    return 0;
}