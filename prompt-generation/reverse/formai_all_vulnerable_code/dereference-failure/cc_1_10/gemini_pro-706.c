//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Insert a node into a binary search tree
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node in a binary search tree
struct node *search(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print a binary search tree
void print(struct node *root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
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

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary search tree
    print(root);

    // Search for a node in the binary search tree
    struct node *found = search(root, 12);
    if (found != NULL) {
        printf("\nFound the node with data %d\n", found->data);
    } else {
        printf("\nNode not found\n");
    }

    // Free the binary search tree
    free_tree(root);

    return 0;
}