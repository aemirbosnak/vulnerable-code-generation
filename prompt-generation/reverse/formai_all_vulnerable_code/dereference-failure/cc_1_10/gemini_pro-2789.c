//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary tree
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

// Print a binary tree in a graphical format
void print_tree(node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);

    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

// Find the height of a binary tree
int find_height(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
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

    // Print the binary tree in a graphical format
    print_tree(root, 0);

    // Find the height of the binary tree
    int height = find_height(root);
    printf("Height of the binary tree: %d\n", height);

    return 0;
}