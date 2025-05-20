//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newNode(int key) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the binary search tree
void insert(struct BSTNode** root, int key) {
    if (!*root) {
        *root = newNode(key);
        return;
    }

    if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a key in the binary search tree
struct BSTNode* search(struct BSTNode* root, int key) {
    if (!root) {
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

// Function to delete a key from the binary search tree
void delete(struct BSTNode** root, int key) {
    if (!*root) {
        return;
    }

    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            struct BSTNode* temp = (*root)->right;
            (*root)->right = (*root)->left;
            (*root)->left = temp;
        } else if ((*root)->right == NULL) {
            struct BSTNode* temp = (*root)->left;
            (*root)->left = (*root)->right;
            (*root)->right = temp;
        } else {
            struct BSTNode* min = NULL;
            struct BSTNode* temp = (*root)->left;
            while (temp->right != NULL) {
                min = temp;
                temp = temp->right;
            }
            temp->right = (*root)->right;
            (*root)->right = min;
        }
    }
}

int main() {
    struct BSTNode* root = NULL;

    // Test cases
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 4);

    struct BSTNode* node = search(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    delete(&root, 5);

    node = search(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}