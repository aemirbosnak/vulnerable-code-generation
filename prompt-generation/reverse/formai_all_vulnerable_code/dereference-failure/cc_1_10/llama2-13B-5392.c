//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 5

// Declare a struct to represent the tree nodes
typedef struct node {
    int data;
    struct node *left, *right;
} node_t;

// Declare a function to create a new node
node_t* new_node(int data) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Declare a function to traverse the tree recursively
void traverse(node_t* root) {
    if (root == NULL) {
        return;
    }

    // Print the node's data
    printf("%d ", root->data);

    // Recursively traverse the left subtree
    traverse(root->left);

    // Print a space
    printf(" ");

    // Recursively traverse the right subtree
    traverse(root->right);
}

int main() {
    // Create a new root node
    node_t* root = new_node(10);

    // Create a new left child node
    root->left = new_node(20);

    // Create a new right child node
    root->right = new_node(30);

    // Traverse the tree recursively
    traverse(root);

    return 0;
}