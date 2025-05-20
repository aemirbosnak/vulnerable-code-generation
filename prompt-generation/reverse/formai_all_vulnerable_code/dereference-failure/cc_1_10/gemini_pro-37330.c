//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: relaxed
// A simple C program to visualize a binary tree
// using ASCII art

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Print a binary tree using ASCII art
void print_tree(node *root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the current node
    printf("%*s%d\n", level * 4, "", root->data);

    // Print the left subtree
    print_tree(root->left, level + 1);

    // Print the right subtree
    print_tree(root->right, level + 1);
}

// Free the memory allocated for a binary tree
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }

    // Free the left subtree
    free_tree(root->left);

    // Free the right subtree
    free_tree(root->right);

    // Free the current node
    free(root);
}

// Main function
int main() {
    // Create a binary tree
    node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary tree using ASCII art
    print_tree(root, 0);

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}