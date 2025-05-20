//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in a binary tree
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
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Print the binary tree in a pre-order traversal
void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

// Print the binary tree in an in-order traversal
void print_tree_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_inorder(root->left);
    printf("%d ", root->data);
    print_tree_inorder(root->right);
}

// Print the binary tree in a post-order traversal
void print_tree_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    printf("%d ", root->data);
}

// Free the memory allocated for a binary tree
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
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

    // Print the binary tree in a pre-order traversal
    printf("Pre-order traversal: ");
    print_tree(root);
    printf("\n");

    // Print the binary tree in an in-order traversal
    printf("In-order traversal: ");
    print_tree_inorder(root);
    printf("\n");

    // Print the binary tree in a post-order traversal
    printf("Post-order traversal: ");
    print_tree_postorder(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}