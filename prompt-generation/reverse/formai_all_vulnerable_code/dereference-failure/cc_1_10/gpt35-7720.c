//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left  = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in BST
int search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root->data;
    }
    if (root->data < value) {
        return search(root->right, value);
    }
    else {
        return search(root->left, value);
    }
}

int main() {
    // Create an empty BST
    struct Node* root = NULL;
    int input[] = { 27, 53, 35, 57, 65, 19, 81, 18, 99, 23 };
    int i;

    // Insert nodes into BST
    for (i = 0; i < 10; i++) {
        root = insert(root, input[i]);
    }

    // Search for a value in BST
    int value = 35;
    if (search(root, value)) {
        printf("%d is present in the BST.\n", value);
    }
    else {
        printf("%d is not present in the BST.\n", value);
    }

    return 0;
}