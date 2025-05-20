//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define node structure for binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a given node in the binary tree
Node* searchNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == data) {
        return root;
    }
    else if (data <= root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Function to print the binary tree in inorder traversal
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 30);
    root = insertNode(root, 3);
    root = insertNode(root, 7);

    // Search for a node in the binary tree
    int searchData = 15;
    Node* node = searchNode(root, searchData);
    if (node != NULL) {
        printf("%d found in the binary tree!\n", searchData);
    }
    else {
        printf("%d not found in the binary tree.\n", searchData);
    }

    // Print the binary tree in inorder traversal
    printf("Binary tree in inorder traversal: ");
    printInorder(root);
    printf("\n");

    return 0;
}