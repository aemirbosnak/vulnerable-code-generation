//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: recursive
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

// Function to perform a recursive binary search
struct BSTNode* binarySearch(struct BSTNode* root, int target) {
    if (root == NULL) return NULL;

    if (target < root->data) {
        return binarySearch(root->left, target);
    } else if (target > root->data) {
        return binarySearch(root->right, target);
    } else {
        return root;
    }
}

// Function to insert a new node into the binary search tree
struct BSTNode* insertBST(struct BSTNode* root, int data) {
    if (root == NULL) {
        root = newBSTNode(data);
    } else {
        if (data < root->data) {
            root->left = insertBST(root->left, data);
        } else {
            root->right = insertBST(root->right, data);
        }
    }
    return root;
}

// Function to traverse the binary search tree
void traverseBST(struct BSTNode* root) {
    if (root != NULL) {
        traverseBST(root->left);
        printf("%d ", root->data);
        traverseBST(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;

    // Test case 1: Empty tree
    root = insertBST(root, 5);
    traverseBST(root);

    // Test case 2: Single node tree
    root = insertBST(root, 2);
    traverseBST(root);

    // Test case 3: Binary search
    root = insertBST(root, 10);
    root = insertBST(root, 8);
    root = insertBST(root, 6);
    struct BSTNode* found = binarySearch(root, 8);
    if (found != NULL) {
        printf("Found %d at position %d\n", found->data, found->left == NULL ? 0 : 1 + (found->left->data < found->data));
    } else {
        printf("Not found\n");
    }

    return 0;
}