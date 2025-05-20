//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define BST Node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} BSTNode;

// Function to insert a new node in BST
BSTNode* insert(BSTNode* root, int key) {
    if (root == NULL)
        return (BSTNode*)malloc(sizeof(BSTNode));

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to find minimum value in BST
int minValue(BSTNode* root) {
    while (root->left!= NULL)
        root = root->left;
    return root->data;
}

// Function to delete a node from BST
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;

        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

int main() {
    // Create a BST
    BSTNode* root = NULL;

    // Insert nodes in BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 15);
    insert(root, 35);
    insert(root, 5);
    insert(root, 40);

    // Find minimum value in BST
    printf("Minimum value in BST is: %d\n", minValue(root));

    // Delete a node from BST
    root = deleteNode(root, 15);

    // Find minimum value in BST after deletion
    printf("Minimum value in BST after deletion is: %d\n", minValue(root));

    return 0;
}