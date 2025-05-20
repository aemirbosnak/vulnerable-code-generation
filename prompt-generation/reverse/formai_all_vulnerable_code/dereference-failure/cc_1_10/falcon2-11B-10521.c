//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insert(struct Node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
        return;
    }

    if (key < root->key) {
        insert(root->left, key);
    } else if (key > root->key) {
        insert(root->right, key);
    }
}

// Function to print the binary search tree
void printBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printBST(root->left);
    printf("%d ", root->key);
    printBST(root->right);
}

// Main function
int main() {
    // Create a new binary search tree
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 1);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    // Print the binary search tree
    printf("Binary Search Tree: \n");
    printBST(root);

    return 0;
}