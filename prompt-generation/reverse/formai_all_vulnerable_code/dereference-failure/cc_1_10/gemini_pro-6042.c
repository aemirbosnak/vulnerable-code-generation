//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// A node in the decentralized search tree
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given value
node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new value into the decentralized search tree
void insert(node **root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }

    if (value < (*root)->value) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

// Search for a value in the decentralized search tree
int search(node *root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->value == value) {
        return 1;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Print the decentralized search tree in order
void print_tree(node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

// Free the memory allocated for the decentralized search tree
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    // Create a decentralized search tree
    node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    // Print the decentralized search tree in order
    print_tree(root);
    printf("\n");

    // Search for a value in the decentralized search tree
    int value = 40;
    if (search(root, value)) {
        printf("The value %d was found in the decentralized search tree.\n", value);
    } else {
        printf("The value %d was not found in the decentralized search tree.\n", value);
    }

    // Free the memory allocated for the decentralized search tree
    free_tree(root);

    return 0;
}