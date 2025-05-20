//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new binary search tree node
struct node *new_node(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Insert a new node into a binary search tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return new_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
    }

    return root;
}

// Search for a node in a binary search tree
struct node *search_node(struct node *root, int data) {
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

    return NULL;
}

// Print the data in a binary search tree in ascending order
void print_bst(struct node *root) {
    if (root != NULL) {
        print_bst(root->left);
        printf("%d ", root->data);
        print_bst(root->right);
    }
}

// Free the memory allocated for a binary search tree
void free_bst(struct node *root) {
    if (root != NULL) {
        free_bst(root->left);
        free_bst(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the data in the binary search tree in ascending order
    print_bst(root);

    // Search for a node in the binary search tree
    struct node *node = search_node(root, 15);
    if (node != NULL) {
        printf("\nNode found: %d", node->data);
    } else {
        printf("\nNode not found");
    }

    // Free the memory allocated for the binary search tree
    free_bst(root);

    return 0;
}