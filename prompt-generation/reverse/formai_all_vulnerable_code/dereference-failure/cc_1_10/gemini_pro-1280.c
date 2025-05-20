//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A node in a binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary search tree
node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
        return root;
    }
}

// Search for a node in a binary search tree
node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else {
        if (data == root->data) {
            return root;
        } else if (data <= root->data) {
            return search_node(root->left, data);
        } else {
            return search_node(root->right, data);
        }
    }
}

// Print a binary search tree in order
void print_tree(node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

// Destroy a binary search tree
void destroy_tree(node *root) {
    if (root != NULL) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }
}

int main() {
    // Create a binary search tree
    node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary search tree
    print_tree(root);

    // Search for a node in the binary search tree
    node *found = search_node(root, 7);
    if (found != NULL) {
        printf("\nFound node with data %d\n", found->data);
    } else {
        printf("\nNode not found\n");
    }

    // Destroy the binary search tree
    destroy_tree(root);

    return 0;
}