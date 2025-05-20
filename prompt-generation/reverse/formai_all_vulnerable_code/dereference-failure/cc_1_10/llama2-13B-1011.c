//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new node with a given key
struct BSTNode *newNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a key into the binary search tree
void insert(struct BSTNode **root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a key in the binary search tree
struct BSTNode *search(struct BSTNode *root, int key) {
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

// Function to traverse the binary search tree
void traverse(struct BSTNode *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int main() {
    struct BSTNode *root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 1);

    struct BSTNode *found = search(root, 4);
    if (found != NULL) {
        printf("Found %d\n", found->key);
    } else {
        printf("Not found\n");
    }

    traverse(root);

    return 0;
}