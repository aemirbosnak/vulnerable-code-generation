//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a binary tree node
typedef struct binary_tree_node {
    int data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_node_t;

// Function to create a new binary tree node
binary_tree_node_t* new_binary_tree_node(int data) {
    binary_tree_node_t* node = (binary_tree_node_t*) malloc(sizeof(binary_tree_node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary tree
binary_tree_node_t* insert_node(binary_tree_node_t* root, int data) {
    if (root == NULL) {
        return new_binary_tree_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Function to traverse the binary tree
void traverse(binary_tree_node_t* root) {
    if (root == NULL) {
        return;
    }

    printf("Data: %d\n", root->data);
    traverse(root->left);
    traverse(root->right);
}

int main() {
    binary_tree_node_t* root = NULL;

    // Create a binary tree
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 2);
    root = insert_node(root, 4);

    // Traverse the binary tree
    traverse(root);

    return 0;
}