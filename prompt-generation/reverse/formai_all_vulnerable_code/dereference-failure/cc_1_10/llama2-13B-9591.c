//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the binary search tree
struct BSTNode {
    int key;   // Key value of the node
    struct BSTNode *left;  // Pointer to the left child node
    struct BSTNode *right; // Pointer to the right child node
    struct BSTNode *parent; // Pointer to the parent node
};

// Function to create a new node with a given key value
struct BSTNode *newNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insertNode(struct BSTNode **root, int key) {
    struct BSTNode *node = newNode(key);

    if (*root == NULL) {
        *root = node;
    } else {
        if (key < (*root)->key) {
            (*root)->left = node;
        } else {
            (*root)->right = node;
        }
        node->parent = *root;
    }
}

// Function to search for a node in the binary search tree
struct BSTNode *searchNode(struct BSTNode *root, int key) {
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
void traverse(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->key);
    traverse(root->left);
    traverse(root->right);
}

// Main function to test the binary search tree
int main() {
    struct BSTNode *root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 9);

    struct BSTNode *node = searchNode(root, 7);
    if (node != NULL) {
        printf("Found node with key %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    traverse(root);

    return 0;
}