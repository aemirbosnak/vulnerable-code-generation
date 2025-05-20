//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new node with a given key
struct BSTNode* newNode(int key) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert(struct BSTNode** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a node in the tree
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

// Function to delete a node from the tree
void delete(struct BSTNode** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        // Delete the current node
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            (*root)->right = NULL;
        } else if ((*root)->right == NULL) {
            (*root)->left = NULL;
        } else {
            // Find the smallest node in the right subtree and make it the new root
            struct BSTNode* minNode = NULL;
            struct BSTNode* temp = (*root)->right;
            while (temp->left != NULL) {
                minNode = temp;
                temp = temp->left;
            }
            // Remove the current node and make minNode the new root
            delete(&(*root)->right, minNode->key);
            (*root)->key = minNode->key;
            (*root)->left = minNode->left;
            minNode->left = NULL;
        }
    }
}

int main() {
    struct BSTNode* root = NULL;
    int key;

    // Insert some nodes into the tree
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 8);
    insert(&root, 2);
    insert(&root, 12);

    // Search for a node in the tree
    struct BSTNode* node = search(root, 8);
    if (node != NULL) {
        printf("Found node with key %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the tree
    delete(&root, 5);

    // Search for the node again
    node = search(root, 5);
    if (node != NULL) {
        printf("Found node with key %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    return 0;
}