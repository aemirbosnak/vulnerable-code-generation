//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A binary search tree
struct bst {
    struct node *root;
};

// Create a new binary search tree
struct bst *new_bst() {
    struct bst *tree = malloc(sizeof(struct bst));
    tree->root = NULL;
    return tree;
}

// Insert a value into a binary search tree
void bst_insert(struct bst *tree, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct node *current = tree->root;
        while (1) {
            if (value < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Search for a value in a binary search tree
struct node *bst_search(struct bst *tree, int value) {
    struct node *current = tree->root;

    while (current != NULL) {
        if (value == current->data) {
            return current;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

// Print a binary search tree
void bst_print(struct bst *tree) {
    struct node *current = tree->root;

    printf("(");

    if (current != NULL) {
        printf("%d", current->data);

        if (current->left != NULL) {
            bst_print(current->left);
        }

        if (current->right != NULL) {
            bst_print(current->right);
        }
    }

    printf(")");
}

// Free the memory used by a binary search tree
void bst_free(struct bst *tree) {
    struct node *current = tree->root;

    if (current != NULL) {
        bst_free(current->left);
        bst_free(current->right);
        free(current);
    }

    free(tree);
}

int main() {
    // Create a new binary search tree
    struct bst *tree = new_bst();

    // Insert some values into the tree
    bst_insert(tree, 10);
    bst_insert(tree, 5);
    bst_insert(tree, 15);
    bst_insert(tree, 2);
    bst_insert(tree, 7);
    bst_insert(tree, 12);
    bst_insert(tree, 20);

    // Print the tree
    bst_print(tree);

    // Search for a value in the tree
    struct node *node = bst_search(tree, 15);

    if (node != NULL) {
        printf("Found the value %d in the tree\n", node->data);
    } else {
        printf("Value not found in the tree\n");
    }

    // Free the memory used by the tree
    bst_free(tree);

    return 0;
}