//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node representing a binary search tree
struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new node with a given key
struct BSTNode* newNode(int key) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert(struct BSTNode** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* search(struct BSTNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to delete a node from the binary search tree
void delete(struct BSTNode** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else {
        delete(&(*root)->right, key);
    }
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
    }
}

// Function to print the binary search tree
void print(struct BSTNode* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->key);
    print(root->right);
}

int main() {
    struct BSTNode* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    print(root);
    delete(&root, 7);
    print(root);
    delete(&root, 2);
    print(root);
    return 0;
}