//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

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
struct BSTNode* insert(struct BSTNode** root_ref, int key) {
    struct BSTNode* root = *root_ref;

    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->data) {
        root->left = insert( &root->left, key );
    } else {
        root->right = insert( &root->right, key );
    }

    return root;
}

// Function to delete a node from the tree
struct BSTNode* delete(struct BSTNode** root_ref, int key) {
    struct BSTNode* root = *root_ref;

    if (root == NULL) {
        return NULL;
    } else if (key < root->data) {
        root->left = delete( &root->left, key );
    } else {
        root->right = delete( &root->right, key );
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    return root;
}

int main() {
    struct BSTNode* root = NULL;

    // Test cases
    root = insert(&root, 5);
    root = insert(&root, 3);
    root = insert(&root, 7);
    root = insert(&root, 2);
    root = insert(&root, 4);

    // Search tests
    printf("Searching for 3... ");
    struct BSTNode* node = search(root, 3);
    printf("%d\n", node->data);

    printf("Searching for 7... ");
    node = search(root, 7);
    printf("%d\n", node->data);

    // Delete tests
    printf("Deleting 3... ");
    root = delete(&root, 3);
    printf("%d\n", root->data);

    printf("Deleting 7... ");
    root = delete(&root, 7);
    printf("%d\n", root->data);

    return 0;
}