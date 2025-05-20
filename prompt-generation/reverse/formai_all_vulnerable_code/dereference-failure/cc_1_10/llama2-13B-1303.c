//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new node with the given data
struct BSTNode* newNode(int data) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert(struct BSTNode** root, int data) {
    struct BSTNode* current = *root;
    if (!current) {
        *root = newNode(data);
        return;
    }

    if (data < current->data) {
        insert(&current->left, data);
    } else {
        insert(&current->right, data);
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* search(struct BSTNode* root, int data) {
    while (root != NULL) {
        if (data < root->data) {
            root = root->left;
        } else if (data > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

// Function to traverse the binary search tree
void traverse(struct BSTNode* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);

    struct BSTNode* found = search(root, 5);
    if (found != NULL) {
        printf("Found %d at %p\n", found->data, found);
    } else {
        printf("Not found\n");
    }

    traverse(root);

    return 0;
}