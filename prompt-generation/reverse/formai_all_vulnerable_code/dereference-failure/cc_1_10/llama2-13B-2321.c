//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a tree node
typedef struct tree_node {
    int data;
    struct tree_node *left, *right;
} tree_node_t;

// Define a function to create a tree node
tree_node_t *new_tree_node(int data) {
    tree_node_t *node = (tree_node_t *)malloc(sizeof(tree_node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to print a tree
void print_tree(tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("Tree Node: %d\n", root->data);

    // Recursively print the left subtree
    print_tree(root->left);

    // Print a line separator
    printf("\n");

    // Recursively print the right subtree
    print_tree(root->right);
}

// Define the recursive function to build the tree
tree_node_t *build_tree(int data) {
    // Base case: if the data is 1, return a tree with only one node
    if (data == 1) {
        tree_node_t *node = new_tree_node(data);
        return node;
    }

    // Recursively build the left subtree
    tree_node_t *left = build_tree(data - 1);

    // Recursively build the right subtree
    tree_node_t *right = build_tree(data - 1);

    // Create a new tree node with the given data and the left and right subtrees
    tree_node_t *root = new_tree_node(data);
    root->left = left;
    root->right = right;

    return root;
}

int main() {
    // Build the tree using the recursive function
    tree_node_t *root = build_tree(5);

    // Print the tree
    print_tree(root);

    return 0;
}