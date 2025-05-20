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

// Function to insert a node into the binary search tree
void insert(struct BSTNode** root, int data) {
    struct BSTNode* node = *root;
    if (node == NULL) {
        *root = newNode(data);
    } else if (data < node->data) {
        insert(&node->left, data);
    } else {
        insert(&node->right, data);
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* search(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to print the binary search tree
void print(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
}

int main() {
    struct BSTNode* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 9);
    insert(&root, 1);
    print(root);
    return 0;
}