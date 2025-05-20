//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new binary search tree node
struct BSTNode* newNode(int data) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a binary search in the tree
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

// Function to insert a new element into the tree
void insert(struct BSTNode** root_ref, int key, int data) {
    struct BSTNode* root = *root_ref;

    if (root == NULL) {
        root = newNode(data);
        *root_ref = root;
        return;
    }

    if (key < root->data) {
        insert(&root->left, key, data);
    } else if (key > root->data) {
        insert(&root->right, key, data);
    } else {
        // Key already exists, do nothing
        return;
    }
}

// Function to traverse the tree
void traverse(struct BSTNode* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;

    insert(&root, 5, 10);
    insert(&root, 2, 5);
    insert(&root, 8, 15);
    insert(&root, 3, 8);

    traverse(root);

    return 0;
}