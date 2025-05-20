//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node
node *new_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
node *insert(node *root, int data) {
    if (root == NULL) {
        return new_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Print a binary tree in a 2D representation
void print_tree(node *root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase the space between levels
    space += 10;

    // Process right child first
    print_tree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    print_tree(root->left, space);
}

// Main function
int main() {
    // Create a binary tree
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary tree
    print_tree(root, 0);

    return 0;
}