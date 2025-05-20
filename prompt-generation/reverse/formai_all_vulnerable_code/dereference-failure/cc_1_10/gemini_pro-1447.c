//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Insert a node into a binary search tree
node* insert(node *root, int data) {
    if (root == NULL) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Duplicate data value: %d\n", data);
    }
    return root;
}

// Search for a node in a binary search tree
node* search(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Print a binary search tree in order
void print_inorder(node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

// Free the memory allocated for a binary search tree
void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a binary search tree
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary search tree in order
    printf("Binary search tree in order: ");
    print_inorder(root);
    printf("\n");

    // Search for a node in the binary search tree
    node *found_node = search(root, 12);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    // Free the memory allocated for the binary search tree
    free_tree(root);

    return 0;
}