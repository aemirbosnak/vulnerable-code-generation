//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into the binary search tree
void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Search for a node in the binary search tree
node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print the binary search tree in order
void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Free the binary search tree
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
    // Create a binary search tree
    node *root = NULL;

    // Insert some nodes into the binary search tree
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    // Print the binary search tree in order
    print_tree(root);
    printf("\n");

    // Search for a node in the binary search tree
    node *found_node = search_node(root, 12);
    if (found_node == NULL) {
        printf("Node not found.\n");
    } else {
        printf("Node found: %d\n", found_node->data);
    }

    // Free the binary search tree
    free_tree(root);

    return 0;
}