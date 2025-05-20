//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: scientific
// BinarySearchTree.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to represent a binary search tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertNode(struct Node** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insertNode(&(*root)->left, key);
    } else {
        insertNode(&(*root)->right, key);
    }
}

// Function to search for a specific key in the binary search tree
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {
        return searchNode(root->left, key);
    } else if (key > root->key) {
        return searchNode(root->right, key);
    } else {
        return root;
    }
}

// Function to traverse the binary search tree
void traverse(struct Node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes into the binary search tree
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 8);
    insertNode(&root, 2);
    insertNode(&root, 12);

    // Search for a specific key in the binary search tree
    struct Node* node = searchNode(root, 8);
    if (node != NULL) {
        printf("Found key %d at depth %d\n", node->key, depth(node));
    } else {
        printf("Key not found\n");
    }

    // Traverse the binary search tree
    traverse(root);

    return 0;
}

// Helper function to calculate the depth of a node
int depth(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + depth(node->left) + depth(node->right);
}