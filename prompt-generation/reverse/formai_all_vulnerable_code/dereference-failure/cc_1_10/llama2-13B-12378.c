//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the search tree
typedef struct node {
    int key;   // Key of the node
    struct node *left;  // Left child node
    struct node *right; // Right child node
} Node;

// Function to create a new node
Node *new_node(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search for a key in the search tree
Node *search(Node *root, int key) {
    // Base case: If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Compare the key with the root's key
    if (root->key == key) {
        // Found the key, return the root node
        return root;
    }

    // Recursive case: Search the left and right child nodes
    Node *left = search(root->left, key);
    Node *right = search(root->right, key);

    // If the key is found in the left child node, return the left child node
    if (left != NULL) {
        return left;
    }

    // If the key is found in the right child node, return the right child node
    if (right != NULL) {
        return right;
    }

    // If the key is not found in the search tree, return NULL
    return NULL;
}

int main() {
    // Create a search tree with the following keys and nodes
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    // Search for the key 4
    Node *found = search(root, 4);

    // Print the found node, or NULL if not found
    if (found != NULL) {
        printf("Found key %d in node %d\n", found->key, found->left->key);
    } else {
        printf("Key not found\n");
    }

    return 0;
}