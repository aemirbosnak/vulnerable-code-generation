//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a binary tree node
typedef struct binary_node {
    int data;
    struct binary_node *left;
    struct binary_node *right;
} binary_node_t;

// Function to create a new binary tree node
binary_node_t* new_node(int data) {
    binary_node_t* node = (binary_node_t*)malloc(sizeof(binary_node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary tree
binary_node_t* insert_node(binary_node_t* root, int data) {
    if (root == NULL) {
        return new_node(data);
    }

    if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Function to traverse the binary tree
void traverse(binary_node_t* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    binary_node_t* root = NULL;

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