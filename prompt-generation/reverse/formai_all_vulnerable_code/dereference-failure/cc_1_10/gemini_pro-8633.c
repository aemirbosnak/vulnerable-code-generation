//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a node for a binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Insert a node into a binary search tree
struct node* insert(struct node *root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // If the data is less than the root, insert it into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // If the data is greater than the root, insert it into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the root of the tree
    return root;
}

// Search for a node in a binary search tree
struct node* search(struct node *root, int data) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is equal to the root, return the root
    if (data == root->data) {
        return root;
    }

    // If the data is less than the root, search for it in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }

    // If the data is greater than the root, search for it in the right subtree
    else if (data > root->data) {
        return search(root->right, data);
    }

    // Return NULL if the data is not found
    return NULL;
}

// Print a binary search tree in order
void print_inorder(struct node *root) {
    // If the tree is empty, do nothing
    if (root == NULL) {
        return;
    }

    // Print the left subtree
    print_inorder(root->left);

    // Print the root
    printf("%d ", root->data);

    // Print the right subtree
    print_inorder(root->right);
}

// Free the memory allocated for a binary search tree
void free_tree(struct node *root) {
    // If the tree is empty, do nothing
    if (root == NULL) {
        return;
    }

    // Free the left subtree
    free_tree(root->left);

    // Free the right subtree
    free_tree(root->right);

    // Free the root
    free(root);
}

// Driver code
int main() {
    srand(time(NULL));
    
    // Create a binary search tree
    struct node *root = NULL;
    for (int i = 0; i < 100; i++) {
        int data = rand() % 1000;
        root = insert(root, data);
    }

    // Print the binary search tree in order
    print_inorder(root);

    // Search for a node in the binary search tree
    int data = rand() % 1000;
    struct node *node = search(root, data);
    if (node != NULL) {
        printf("\nFound node with data %d\n", node->data);
    } else {
        printf("\nNode with data %d not found\n", data);
    }

    // Free the memory allocated for the binary search tree
    free_tree(root);

    return 0;
}