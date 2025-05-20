//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode *newBSTNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new element into the binary search tree
void insertBST(struct BSTNode **root, int key) {
    struct BSTNode *node = *root;

    // If the root is NULL, create a new node with the given key
    if (!node) {
        node = newBSTNode(key);
        *root = node;
        return;
    }

    // If the key is less than the root's key, insert to the left
    if (key < node->key) {
        if (!node->left) {
            node->left = newBSTNode(key);
        } else {
            insertBST(&node->left, key);
        }
    } else {
        // If the key is greater than the root's key, insert to the right
        if (!node->right) {
            node->right = newBSTNode(key);
        } else {
            insertBST(&node->right, key);
        }
    }
}

// Function to search for an element in the binary search tree
struct BSTNode *searchBST(struct BSTNode *root, int key) {
    struct BSTNode *node = root;

    // If the root is NULL, return NULL
    if (!node) {
        return NULL;
    }

    // If the key is less than the root's key, search the left subtree
    if (key < node->key) {
        node = searchBST(node->left, key);
        if (node) {
            return node;
        }
    } else {
        // If the key is greater than the root's key, search the right subtree
        node = searchBST(node->right, key);
        if (node) {
            return node;
        }
    }

    // If we reach a NULL node, return NULL
    return NULL;
}

// Example usage:
int main() {
    struct BSTNode *root = NULL;

    insertBST(&root, 5);
    insertBST(&root, 3);
    insertBST(&root, 7);
    insertBST(&root, 2);
    insertBST(&root, 4);

    struct BSTNode *found = searchBST(root, 5);
    if (found) {
        printf("Found %d in the tree\n", found->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}