//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define our data structure, which is a binary tree node
typedef struct binary_tree_node {
    int data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_node;

// Function to create a new binary tree node
binary_tree_node *create_node(int data) {
    binary_tree_node *new_node = (binary_tree_node *)malloc(sizeof(binary_tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary tree
binary_tree_node *insert_node(binary_tree_node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to visualize the binary tree
void visualize_tree(binary_tree_node *root, int level) {
    if (root == NULL) {
        return;
    }
    visualize_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d\n", root->data);
    visualize_tree(root->left, level + 1);
}

int main() {
    // Create a new binary tree
    binary_tree_node *root = create_node(5);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 1);
    insert_node(root, 9);
    insert_node(root, 4);
    insert_node(root, 2);
    insert_node(root, 8);
    insert_node(root, 6);

    // Visualize the binary tree
    visualize_tree(root, 0);

    return 0;
}