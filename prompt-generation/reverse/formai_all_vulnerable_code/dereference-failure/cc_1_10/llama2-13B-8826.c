//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

// Structure to represent a node in the search tree
typedef struct node {
    int key;
    struct node *left, *right;
} node_t;

// Function to create a new node with the given key
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

    if (root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    // Create a search tree with the following keys:
    //   4, 2, 1, 3, 5, 6, 7
    node_t *root = new_node(4);
    root->left = new_node(2);
    root->left->left = new_node(1);
    root->left->right = new_node(3);
    root->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    // Search for the key 3
    node_t *result = search(root, 3);

    // Print the result
    if (result != NULL) {
        printf("Found key %d\n", result->key);
    } else {
        printf("Key not found\n");
    }

    return 0;
}