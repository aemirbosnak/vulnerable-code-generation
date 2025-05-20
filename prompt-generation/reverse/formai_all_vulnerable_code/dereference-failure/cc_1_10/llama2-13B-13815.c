//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new binary search tree node
struct BSTNode *newBSTNode(int key) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertBST(struct BSTNode **root, int key) {
    if (*root == NULL) {
        *root = newBSTNode(key);
    } else if (key < (*root)->key) {
        insertBST(&(*root)->left, key);
    } else {
        insertBST(&(*root)->right, key);
    }
}

// Function to search for a specific key in the binary search tree
struct BSTNode *searchBST(struct BSTNode *root, int key) {
    if (root == NULL) {
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

// Function to delete a node from the binary search tree
void deleteBST(struct BSTNode **root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        deleteBST(&(*root)->left, key);
    } else if (key > (*root)->key) {
        deleteBST(&(*root)->right, key);
    } else {
        // Found the node to delete, replace it with the smallest node in its subtree
        struct BSTNode *min = NULL;
        struct BSTNode *tmp = *root;

        while (tmp->left != NULL) {
            min = tmp->left;
            tmp = min->right;
        }

        if (min != NULL) {
            min->right = tmp->right;
            if (tmp->right == NULL) {
                min->left = NULL;
            }
        } else {
            // The deleted node had no children, just set the pointer to NULL
            *root = tmp->right;
        }

        free(tmp);
    }
}

int main() {
    struct BSTNode *root = NULL;

    // Insert some nodes into the binary search tree
    insertBST(&root, 10);
    insertBST(&root, 5);
    insertBST(&root, 8);
    insertBST(&root, 3);
    insertBST(&root, 6);
    insertBST(&root, 12);

    // Search for a specific key in the binary search tree
    struct BSTNode *node = searchBST(root, 8);

    // Delete a node from the binary search tree
    deleteBST(&root, 10);

    // Print the remaining nodes in the binary search tree
    struct BSTNode *current = root;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->right;
    }

    return 0;
}