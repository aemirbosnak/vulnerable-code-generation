//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a tree node
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

// Define a function to create a new tree node
tree_node_t *new_tree_node(int data) {
    tree_node_t *node = (tree_node_t *)malloc(sizeof(tree_node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to traverse the tree
void traverse_tree(tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    traverse_tree(root->left);

    // Traverse the right subtree
    traverse_tree(root->right);
}

// Define a function to insert a new node into the tree
tree_node_t *insert_node(tree_node_t *root, int data) {
    if (root == NULL) {
        return new_tree_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

int main() {
    // Create a new tree node with data 1
    tree_node_t *root = new_tree_node(1);

    // Insert new nodes with data 2, 3, and 4
    root = insert_node(root, 2);
    root = insert_node(root, 3);
    root = insert_node(root, 4);

    // Traverse the tree
    traverse_tree(root);

    return 0;
}