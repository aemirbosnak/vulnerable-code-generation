//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a binary tree node
struct binary_tree {
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
};

// Define a function to print the tree
void print_tree(struct binary_tree *tree) {
    if (tree == NULL) {
        return;
    }

    printf("Data: %d\n", tree->data);
    print_tree(tree->left);
    print_tree(tree->right);
}

// Define a function to create a new node
struct binary_tree *new_node(int data) {
    struct binary_tree *node = malloc(sizeof(struct binary_tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to insert a node into the tree
struct binary_tree *insert_node(struct binary_tree *tree, int data) {
    if (tree == NULL) {
        return new_node(data);
    }

    if (data < tree->data) {
        tree->left = insert_node(tree->left, data);
    } else {
        tree->right = insert_node(tree->right, data);
    }

    return tree;
}

int main() {
    struct binary_tree *root = NULL;

    // Create the tree
    root = insert_node(root, 1);
    root = insert_node(root, 2);
    root = insert_node(root, 3);
    root = insert_node(root, 4);
    root = insert_node(root, 5);

    // Print the tree
    print_tree(root);

    return 0;
}