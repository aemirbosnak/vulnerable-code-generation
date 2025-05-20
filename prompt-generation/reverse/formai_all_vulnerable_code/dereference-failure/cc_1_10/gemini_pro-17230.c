//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdlib.h>
#include <stdio.h>

// A binary search tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary search tree
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

// Search for a node in a binary search tree
struct node* search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print a binary search tree
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Free a binary search tree
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
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary search tree
    printf("Binary search tree: ");
    print_tree(root);
    printf("\n");

    // Search for a node in the binary search tree
    struct node *found_node = search_node(root, 12);
    if (found_node == NULL) {
        printf("Node not found.\n");
    } else {
        printf("Node found: %d\n", found_node->data);
    }

    // Free the binary search tree
    free_tree(root);

    return 0;
}