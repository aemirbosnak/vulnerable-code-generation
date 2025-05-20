//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode *newBSTNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertBST(struct BSTNode **root, int key) {
    struct BSTNode *newNode = newBSTNode(key);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    if (key < (*root)->key) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode;
        } else {
            insertBST(&(*root)->left, key);
        }
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = newNode;
        } else {
            insertBST(&(*root)->right, key);
        }
    }
}

// Function to search for a node in the binary search tree
struct BSTNode *searchBST(struct BSTNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

// Function to traverse the binary search tree
void traverseBST(struct BSTNode *root) {
    if (root != NULL) {
        traverseBST(root->left);
        printf("%d ", root->key);
        traverseBST(root->right);
    }
}

int main() {
    struct BSTNode *root = NULL;

    insertBST(&root, 5);
    insertBST(&root, 3);
    insertBST(&root, 7);
    insertBST(&root, 2);
    insertBST(&root, 9);

    struct BSTNode *found = searchBST(root, 7);
    if (found != NULL) {
        printf("Found %d\n", found->key);
    } else {
        printf("Not found\n");
    }

    traverseBST(root);

    return 0;
}