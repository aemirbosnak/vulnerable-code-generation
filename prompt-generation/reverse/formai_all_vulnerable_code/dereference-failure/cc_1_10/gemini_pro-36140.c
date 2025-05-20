//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the data structure for a node in the binary search tree.
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Create a new node with the given value.
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given value into the binary search tree.
struct node *insert_node(struct node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    } else if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

// Search for the given value in the binary search tree.
struct node *search_node(struct node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return search_node(root->left, value);
    } else {
        return search_node(root->right, value);
    }
}

// Print the values of the nodes in the binary search tree in order.
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

// Free the memory allocated for the binary search tree.
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Main function.
int main() {
    // Create a binary search tree.
    struct node *root = NULL;

    // Insert some values into the binary search tree.
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int value = rand() % 100;
        root = insert_node(root, value);
    }

    // Print the values of the nodes in the binary search tree in order.
    print_tree(root);
    printf("\n");

    // Search for a value in the binary search tree.
    int value_to_search = 50;
    struct node *found_node = search_node(root, value_to_search);
    if (found_node == NULL) {
        printf("Value not found.\n");
    } else {
        printf("Value found: %d\n", found_node->value);
    }

    // Free the memory allocated for the binary search tree.
    free_tree(root);

    return 0;
}