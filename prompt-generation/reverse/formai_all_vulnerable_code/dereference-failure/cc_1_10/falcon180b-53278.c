//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for a node in the tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node with the given data into the tree recursively
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to print the tree in a visual format
void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    printTree(root->right, space);

    printf("\n");

    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Main function to test the tree implementation
int main() {
    Node* root = NULL;

    // Insert nodes with the following data: 5 3 7 1 9
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);

    // Print the tree in a visual format
    printTree(root, 0);

    return 0;
}