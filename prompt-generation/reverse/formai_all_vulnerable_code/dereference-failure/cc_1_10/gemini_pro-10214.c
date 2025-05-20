//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for a binary search tree
typedef struct node {
    int value;
    struct node *left, *right;
} node_t;

// Function to create a new node with the given value
node_t *new_node(int value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new value into the binary search tree
node_t *insert(node_t *root, int value) {
    if (root == NULL) {
        return new_node(value);
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the binary search tree
node_t *search(node_t *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to print the binary search tree in order
void print_inorder(node_t *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->value);
        print_inorder(root->right);
    }
}

// Function to free the memory used by the binary search tree
void free_tree(node_t *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Driver code to test the binary search tree
int main() {
    // Create a binary search tree
    node_t *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search for a value in the binary search tree
    node_t *found_node = search(root, 40);
    if (found_node != NULL) {
        printf("Found the value %d in the binary search tree\n", found_node->value);
    } else {
        printf("Value not found in the binary search tree\n");
    }

    // Print the binary search tree in order
    printf("Inorder traversal of the binary search tree: ");
    print_inorder(root);
    printf("\n");

    // Free the memory used by the binary search tree
    free_tree(root);

    return 0;
}