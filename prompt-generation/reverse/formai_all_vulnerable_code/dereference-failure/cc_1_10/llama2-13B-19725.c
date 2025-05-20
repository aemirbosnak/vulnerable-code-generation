//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the search tree
typedef struct node {
    int data;
    struct node *left, *right;
} node_t;

// Function to create a new node
node_t *new_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search for a given value in the search tree
node_t *search(node_t *root, int target) {
    if (root == NULL) {
        return NULL;
    }

    // Check if the target is less than the current node's data
    if (target < root->data) {
        return search(root->left, target);
    }

    // Check if the target is greater than the current node's data
    if (target > root->data) {
        return search(root->right, target);
    }

    // If the target is equal to the current node's data, return the node
    return root;
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

    // Search for the value 4 in the search tree
    node_t *found = search(root, 4);

    // Print the found node
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}