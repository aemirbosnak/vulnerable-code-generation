//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A binary tree
struct tree {
    struct node *root;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
void insert_node(struct tree *tree, struct node *new_node) {
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct node *current_node = tree->root;
        while (1) {
            if (new_node->data < current_node->data) {
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == NULL) {
                    current_node->right = new_node;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
        }
    }
}

// Print a binary tree in a multivariable style
void print_tree(struct tree *tree, int level) {
    if (tree->root == NULL) {
        return;
    }

    // Print the current node
    printf("%d\n", tree->root->data);

    // Print the left subtree
    if (tree->root->left != NULL) {
        print_tree(tree->root->left, level + 1);
    }

    // Print the right subtree
    if (tree->root->right != NULL) {
        print_tree(tree->root->right, level + 1);
    }
}

// Free a binary tree
void free_tree(struct tree *tree) {
    if (tree->root == NULL) {
        return;
    }

    // Free the left subtree
    if (tree->root->left != NULL) {
        free_tree(tree->root->left);
    }

    // Free the right subtree
    if (tree->root->right != NULL) {
        free_tree(tree->root->right);
    }

    // Free the current node
    free(tree->root);
}

int main() {
    // Create a new binary tree
    struct tree *tree = malloc(sizeof(struct tree));
    tree->root = NULL;

    // Insert some nodes into the binary tree
    insert_node(tree, create_node(10));
    insert_node(tree, create_node(5));
    insert_node(tree, create_node(15));
    insert_node(tree, create_node(2));
    insert_node(tree, create_node(7));
    insert_node(tree, create_node(12));
    insert_node(tree, create_node(20));

    // Print the binary tree in a multivariable style
    print_tree(tree, 0);

    // Free the binary tree
    free_tree(tree);

    return 0;
}