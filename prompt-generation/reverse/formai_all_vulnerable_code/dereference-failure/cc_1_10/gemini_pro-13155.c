//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the binary search tree
struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Search for a given value in the binary search tree
struct node* search_node(struct node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->data) {
        return root;
    } else if (value < root->data) {
        return search_node(root->left, value);
    } else {
        return search_node(root->right, value);
    }
}

// Print the binary search tree in order
void print_tree(struct node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

// Free the memory allocated for the binary search tree
void free_tree(struct node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the binary search tree in order
    printf("Binary search tree in order: ");
    print_tree(root);
    printf("\n");

    // Search for a value in the binary search tree
    int value = 40;
    struct node *found_node = search_node(root, value);
    if (found_node != NULL) {
        printf("Found %d in the binary search tree\n", value);
    } else {
        printf("Did not find %d in the binary search tree\n", value);
    }

    // Free the memory allocated for the binary search tree
    free_tree(root);

    return 0;
}