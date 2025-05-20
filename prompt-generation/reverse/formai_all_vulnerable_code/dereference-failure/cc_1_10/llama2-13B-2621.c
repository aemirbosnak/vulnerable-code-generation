//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the search tree
typedef struct node {
    int key;
    struct node *left, *right;
} node_t;

// Function to create a new node
node_t *new_node(int key) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a depth-first search
void dfs(node_t *root) {
    if (root == NULL) {
        return;
    }

    // Print the current node
    printf("%d ", root->key);

    // Recursively search the left and right subtrees
    dfs(root->left);
    dfs(root->right);
}

// Function to perform a bidirectional search
void bidfs(node_t *root) {
    if (root == NULL) {
        return;
    }

    // Print the current node
    printf("%d ", root->key);

    // Recursively search the left subtree
    bidfs(root->left);

    // Print a newline and search the right subtree
    printf("\n");
    bidfs(root->right);
}

int main() {
    // Create a list of nodes
    node_t *root = NULL;
    root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    // Perform a depth-first search
    dfs(root);

    // Perform a bidirectional search
    bidfs(root);

    return 0;
}