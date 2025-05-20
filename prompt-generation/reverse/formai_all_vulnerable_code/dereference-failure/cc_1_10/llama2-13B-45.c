//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode *newBSTNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new key into the binary search tree
void insertBST(struct BSTNode **root, int key) {
    if (!*root) {
        *root = newBSTNode(key);
        return;
    }

    // Search for the appropriate location for the new key
    if (key < (*root)->key) {
        if (!(*root)->left) {
            (*root)->left = newBSTNode(key);
        } else {
            insertBST(&(*root)->left, key);
        }
    } else {
        if (!(*root)->right) {
            (*root)->right = newBSTNode(key);
        } else {
            insertBST(&(*root)->right, key);
        }
    }
}

// Function to search for a key in the binary search tree
struct BSTNode *searchBST(struct BSTNode *root, int key) {
    if (!root) {
        return NULL;
    }

    if (key < root->key) {
        return searchBST(root->left, key);
    } else if (key > root->key) {
        return searchBST(root->right, key);
    } else {
        return root;
    }
}

// Function to delete a key from the binary search tree
void deleteBST(struct BSTNode **root, int key) {
    if (!*root) {
        return;
    }

    if (key < (*root)->key) {
        deleteBST(&(*root)->left, key);
    } else if (key > (*root)->key) {
        deleteBST(&(*root)->right, key);
    } else {
        if ((*root)->left && (*root)->right) {
            // Find the smallest node greater than the key to be deleted
            struct BSTNode *min = NULL;
            struct BSTNode *tmp = (*root)->right;
            while (tmp->left) {
                min = tmp;
                tmp = tmp->left;
            }

            // Replace the current node with the smallest node greater than the key
            (*root)->key = min->key;
            (*root)->left = min->left;
            free(min);
        } else if ((*root)->left) {
            // If the right subtree is empty, just point the current node's left pointer to the smallest node
            struct BSTNode *min = NULL;
            struct BSTNode *tmp = (*root)->left;
            while (tmp->left) {
                min = tmp;
                tmp = tmp->left;
            }

            (*root)->left = min->left;
            free(min);
        } else {
            // If the left subtree is empty, just point the current node's right pointer to the smallest node
            struct BSTNode *min = NULL;
            struct BSTNode *tmp = (*root)->right;
            while (tmp->left) {
                min = tmp;
                tmp = tmp->left;
            }

            (*root)->right = min->left;
            free(min);
        }
    }
}

int main() {
    struct BSTNode *root = NULL;

    // Insert some keys
    insertBST(&root, 10);
    insertBST(&root, 5);
    insertBST(&root, 8);
    insertBST(&root, 3);
    insertBST(&root, 6);
    insertBST(&root, 12);

    // Search for some keys
    struct BSTNode *node = searchBST(root, 5);
    if (node) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    node = searchBST(root, 12);
    if (node) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    // Delete some keys
    deleteBST(&root, 5);
    deleteBST(&root, 8);

    // Print the remaining keys
    struct BSTNode *current = root;
    while (current) {
        printf("%d ", current->key);
        current = current->left;
    }

    return 0;
}