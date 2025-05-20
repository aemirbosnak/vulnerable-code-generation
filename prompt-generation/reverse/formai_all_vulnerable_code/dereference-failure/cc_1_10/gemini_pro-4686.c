//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// This is a node in the binary search tree.
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

// This function creates a new node with the given value.
node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// This function inserts a new node with the given value into the binary search tree.
void insert_node(node **root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else if (value < (*root)->value) {
        insert_node(&(*root)->left, value);
    } else if (value > (*root)->value) {
        insert_node(&(*root)->right, value);
    } else {
        printf("The value %d is already in the tree.\n", value);
    }
}

// This function searches for a node with the given value in the binary search tree.
node *search_node(node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value < root->value) {
        return search_node(root->left, value);
    } else if (value > root->value) {
        return search_node(root->right, value);
    } else {
        return root;
    }
}

// This function prints the binary search tree in order.
void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

// This function frees the memory used by the binary search tree.
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    // Create a binary search tree.
    node *root = NULL;

    // Insert some values into the binary search tree.
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    // Print the binary search tree in order.
    print_tree(root);
    printf("\n");

    // Search for a value in the binary search tree.
    node *found_node = search_node(root, 15);
    if (found_node == NULL) {
        printf("The value 15 was not found in the tree.\n");
    } else {
        printf("The value 15 was found in the tree.\n");
    }

    // Free the memory used by the binary search tree.
    free_tree(root);

    return 0;
}