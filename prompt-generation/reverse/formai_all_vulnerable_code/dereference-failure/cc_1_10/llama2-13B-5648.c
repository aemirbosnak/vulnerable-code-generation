//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newBSTNode(int data) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertBST(struct BSTNode** root, int data) {
    if (*root == NULL) {
        *root = newBSTNode(data);
    } else if (data < (*root)->data) {
        insertBST(&(*root)->left, data);
    } else {
        insertBST(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* searchBST(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return searchBST(root->left, data);
    } else if (data > root->data) {
        return searchBST(root->right, data);
    } else {
        return root;
    }
}

// Function to delete a node from the binary search tree
void deleteBST(struct BSTNode** root, int data) {
    if (*root == NULL) {
        return;
    } else if (data < (*root)->data) {
        deleteBST(&(*root)->left, data);
    } else if (data > (*root)->data) {
        deleteBST(&(*root)->right, data);
    } else {
        // Delete the current node
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left != NULL) {
            // Replace the current node with the left child
            *root = (*root)->left;
        } else {
            // Replace the current node with the right child
            *root = (*root)->right;
        }
    }
}

int main() {
    struct BSTNode* root = NULL;

    // Insert some nodes into the binary search tree
    insertBST(&root, 5);
    insertBST(&root, 3);
    insertBST(&root, 7);
    insertBST(&root, 2);
    insertBST(&root, 9);

    // Search for some nodes in the binary search tree
    struct BSTNode* node1 = searchBST(root, 5);
    struct BSTNode* node2 = searchBST(root, 7);
    struct BSTNode* node3 = searchBST(root, 3);

    // Delete some nodes from the binary search tree
    deleteBST(&root, 7);
    deleteBST(&root, 3);

    // Print the remaining nodes in the binary search tree
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->left;
    }

    return 0;
}