//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary search tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to print the binary search tree in a recursive style
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Function to free the memory allocated to the binary search tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 17);

    // Print the binary search tree
    print_tree(root);

    // Free the memory allocated to the binary search tree
    free_tree(root);

    return 0;
}