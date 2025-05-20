//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newNode(int data) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a binary search on the tree
struct BSTNode* search(struct BSTNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data < key) {
        return search(root->left, key);
    } else if (root->data > key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to insert a new node into the tree
struct BSTNode* insert(struct BSTNode* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (root->data < key) {
        root->left = insert(root->left, key);
    } else if (root->data > key) {
        root->right = insert(root->right, key);
    } else {
        // Key already exists in the tree, do nothing
        return root;
    }

    return root;
}

// Function to delete a node from the tree
struct BSTNode* delete(struct BSTNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data < key) {
        root->left = delete(root->left, key);
    } else if (root->data > key) {
        root->right = delete(root->right, key);
    } else {
        // Key to be deleted is the root node, replace it with the smallest node in the left or right subtree
        struct BSTNode* temp = (root->left == NULL) ? root->right : root->left;
        root->data = temp->data;
        root->left = temp->left;
        root->right = temp->right;
        free(temp);
        return root;
    }

    return root;
}

int main() {
    struct BSTNode* root = NULL;

    // Test cases
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);

    // Search for the value 5
    struct BSTNode* five = search(root, 5);
    printf("Value 5 found at location %p\n", five);

    // Search for the value 2
    struct BSTNode* two = search(root, 2);
    printf("Value 2 found at location %p\n", two);

    // Delete the value 3
    root = delete(root, 3);
    printf("After deleting 3, the tree is %p\n", root);

    // Delete the value 8
    root = delete(root, 8);
    printf("After deleting 8, the tree is %p\n", root);

    return 0;
}