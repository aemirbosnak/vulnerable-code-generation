//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into a binary tree
node* insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to print the binary tree in a visual format
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

// Main function
int main() {
    // Create a binary tree
    node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the binary tree in a visual format
    print_tree(root, 0);

    return 0;
}