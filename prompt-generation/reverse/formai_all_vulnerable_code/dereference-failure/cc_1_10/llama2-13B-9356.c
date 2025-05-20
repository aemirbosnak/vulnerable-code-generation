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

// Function to insert a new element into the binary search tree
void insertBST(struct BSTNode** root, int data) {
    if (!*root) {
        *root = newBSTNode(data);
    } else if (data < (*root)->data) {
        insertBST(&(*root)->left, data);
    } else {
        insertBST(&(*root)->right, data);
    }
}

// Function to search for an element in the binary search tree
int searchBST(struct BSTNode* root, int data) {
    if (!root) {
        return -1;
    }
    if (data < root->data) {
        return searchBST(root->left, data);
    } else if (data > root->data) {
        return searchBST(root->right, data);
    } else {
        return 0;
    }
}

// Function to traverse the binary search tree
void traverseBST(struct BSTNode* root) {
    if (root) {
        traverseBST(root->left);
        printf("%d ", root->data);
        traverseBST(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;
    insertBST(&root, 5);
    insertBST(&root, 2);
    insertBST(&root, 8);
    insertBST(&root, 3);
    insertBST(&root, 1);
    insertBST(&root, 6);

    // Search for 5
    int found = searchBST(root, 5);
    if (found != -1) {
        printf("5 found at %d\n", found);
    } else {
        printf("5 not found\n");
    }

    // Traverse the binary search tree
    traverseBST(root);

    return 0;
}