//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newNode(int data) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a binary search on the tree
struct BSTNode* search(struct BSTNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else if (key > root->data) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to insert a new node into the tree
void insert(struct BSTNode** root_ref, int data) {
    struct BSTNode* root = *root_ref;

    if (root == NULL) {
        root = newNode(data);
        *root_ref = root;
    } else if (data < root->data) {
        insert( &root->left, data );
    } else {
        insert( &root->right, data );
    }
}

// Function to traverse the tree
void traverse(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }

    printf("Node: %d\n", root->data);
    traverse(root->left);
    traverse(root->right);
}

int main() {
    struct BSTNode* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 4);

    traverse(root);

    return 0;
}