//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to hold a node in the search tree
typedef struct node {
    int key;    // Key value of the node
    struct node *left;  // Left child node
    struct node *right; // Right child node
} node_t;

// Function to create a new node
node_t *new_node(int key) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search for a key in the search tree
node_t *search(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    // Compare the key with the current node's key
    if (root->key == key) {
        // Found the key, return the node
        return root;
    }

    // If the key is less than the current node's key, search the left subtree
    if (key < root->key) {
        return search(root->left, key);
    }

    // If the key is greater than the current node's key, search the right subtree
    return search(root->right, key);
}

int main() {
    // Create a search tree with the following nodes
    node_t *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    // Search for the key 4
    node_t *node = search(root, 4);

    // Print the found node, or print "Not found" if the key is not found
    if (node != NULL) {
        printf("Found key %d at node %p\n", node->key, node);
    } else {
        printf("Not found\n");
    }

    return 0;
}