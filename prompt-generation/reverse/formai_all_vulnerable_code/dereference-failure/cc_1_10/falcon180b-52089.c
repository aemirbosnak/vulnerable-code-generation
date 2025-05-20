//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node with the given data into the binary search tree
void insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

// Function to search for a node with the given data in the binary search tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print the binary search tree
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

// Main function to test the binary search tree operations
int main() {
    Node* root = NULL;

    // Insert nodes into the binary search tree
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the binary search tree
    printf("Binary Search Tree:\n");
    printTree(root, 0);

    // Search for a node in the binary search tree
    Node* searchResult = searchNode(root, 40);
    if (searchResult!= NULL) {
        printf("\nNode with data %d found!\n", searchResult->data);
    } else {
        printf("\nNode with data %d not found!\n", 40);
    }

    return 0;
}