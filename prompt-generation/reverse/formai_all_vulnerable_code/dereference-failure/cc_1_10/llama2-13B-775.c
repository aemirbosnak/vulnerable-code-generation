//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new node with a given key
struct BSTNode *newNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insert(struct BSTNode **root, int key) {
    struct BSTNode *node = *root;

    if (!node) {
        *root = newNode(key);
        return;
    }

    if (key < node->key) {
        if (!node->left) {
            node->left = newNode(key);
        } else {
            insert(node->left, key);
        }
    } else if (key > node->key) {
        if (!node->right) {
            node->right = newNode(key);
        } else {
            insert(node->right, key);
        }
    }
}

// Function to search for a node in the binary search tree
struct BSTNode *search(struct BSTNode *root, int key) {
    struct BSTNode *current = root;

    while (current && current->key != key) {
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current;
}

// Function to traverse the binary search tree
void traverse(struct BSTNode *root) {
    if (root) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int main() {
    struct BSTNode *root = NULL;

    insert(&root, 10);
    insert(&root, 8);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 14);
    insert(&root, 18);

    traverse(root);

    return 0;
}