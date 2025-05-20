//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode *newBSTNode(int data) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new element into the binary search tree
void insertBST(struct BSTNode **root, int data) {
    struct BSTNode *newNode = newBSTNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        // Recursive insertion
        if (data < (*root)->data) {
            if ((*root)->left == NULL) {
                (*root)->left = newNode;
            } else {
                insertBST(&(*root)->left, data);
            }
        } else {
            if ((*root)->right == NULL) {
                (*root)->right = newNode;
            } else {
                insertBST(&(*root)->right, data);
            }
        }
    }
}

// Function to search for an element in the binary search tree
struct BSTNode *searchBST(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return searchBST(root->left, data);
    } else if (data > root->data) {
        return searchBST(root->right, data);
    } else {
        return root;
    }
}

int main() {
    struct BSTNode *root = NULL;
    insertBST(&root, 10);
    insertBST(&root, 5);
    insertBST(&root, 8);
    insertBST(&root, 3);
    insertBST(&root, 6);
    insertBST(&root, 12);

    struct BSTNode *node = searchBST(root, 8);
    if (node != NULL) {
        printf("Found %d in the binary search tree\n", node->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}