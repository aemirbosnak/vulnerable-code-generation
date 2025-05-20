//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// This is a very simple implementation of a binary search tree.
// The tree is stored in an array, with the root node at index 0.
// The left child of a node is at index 2*i+1, and the right child is at index 2*i+2.
// The tree is represented as an array of pointers to nodes.
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given data.
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the tree.
void insert_node(node **tree, int data) {
    // If the tree is empty, create a new root node.
    if (*tree == NULL) {
        *tree = create_node(data);
        return;
    }

    // Otherwise, find the correct place to insert the new node.
    node *current_node = *tree;
    while (1) {
        // If the data is less than the current node's data, go left.
        if (data < current_node->data) {
            if (current_node->left == NULL) {
                current_node->left = create_node(data);
                return;
            } else {
                current_node = current_node->left;
            }
        // Otherwise, go right.
        } else {
            if (current_node->right == NULL) {
                current_node->right = create_node(data);
                return;
            } else {
                current_node = current_node->right;
            }
        }
    }
}

// Print the tree in preorder (root, left, right).
void preorder(node *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

// Print the tree in inorder (left, root, right).
void inorder(node *tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

// Print the tree in postorder (left, right, root).
void postorder(node *tree) {
    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->data);
}

// Free the tree.
void free_tree(node *tree) {
    if (tree == NULL) {
        return;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

int main() {
    // Create a new binary search tree.
    node *tree = NULL;

    // Insert some data into the tree.
    insert_node(&tree, 10);
    insert_node(&tree, 5);
    insert_node(&tree, 15);
    insert_node(&tree, 2);
    insert_node(&tree, 7);
    insert_node(&tree, 12);
    insert_node(&tree, 20);

    // Print the tree in preorder.
    printf("Preorder: ");
    preorder(tree);
    printf("\n");

    // Print the tree in inorder.
    printf("Inorder: ");
    inorder(tree);
    printf("\n");

    // Print the tree in postorder.
    printf("Postorder: ");
    postorder(tree);
    printf("\n");

    // Free the tree.
    free_tree(tree);

    return 0;
}