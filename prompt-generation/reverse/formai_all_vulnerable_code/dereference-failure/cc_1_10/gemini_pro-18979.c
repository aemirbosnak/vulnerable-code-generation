//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdlib.h>
#include <stdio.h>

// A binary search tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A binary search tree
struct tree {
    struct node *root;
};

// Create a new binary search tree
struct tree *create_tree() {
    struct tree *tree = malloc(sizeof(struct tree));
    tree->root = NULL;
    return tree;
}

// Insert a new node into a binary search tree
void insert(struct tree *tree, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    // If the tree is empty, the new node becomes the root
    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    // Otherwise, we need to find the correct place to insert the new node
    struct node *current_node = tree->root;
    while (1) {
        // If the new node's data is less than the current node's data, we go left
        if (data < current_node->data) {
            if (current_node->left == NULL) {
                current_node->left = new_node;
                return;
            } else {
                current_node = current_node->left;
            }
        }
        // Otherwise, we go right
        else {
            if (current_node->right == NULL) {
                current_node->right = new_node;
                return;
            } else {
                current_node = current_node->right;
            }
        }
    }
}

// Search for a node in a binary search tree
struct node *search(struct tree *tree, int data) {
    struct node *current_node = tree->root;

    while (current_node != NULL) {
        // If the data we're looking for is equal to the current node's data, we've found it
        if (data == current_node->data) {
            return current_node;
        }
        // Otherwise, we need to keep searching
        else if (data < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    // If we've reached the end of the tree without finding the data we're looking for,
    // then the data is not in the tree
    return NULL;
}

// Delete a node from a binary search tree
void delete(struct tree *tree, int data) {
    struct node *current_node = tree->root;
    struct node *parent_node = NULL;

    // Find the node to delete
    while (current_node != NULL) {
        if (data == current_node->data) {
            break;
        } else if (data < current_node->data) {
            parent_node = current_node;
            current_node = current_node->left;
        } else {
            parent_node = current_node;
            current_node = current_node->right;
        }
    }

    // If the node to delete is not in the tree, we can't delete it
    if (current_node == NULL) {
        return;
    }

    // If the node to delete is a leaf node, we can simply remove it
    if (current_node->left == NULL && current_node->right == NULL) {
        if (parent_node == NULL) {
            tree->root = NULL;
        } else if (parent_node->left == current_node) {
            parent_node->left = NULL;
        } else {
            parent_node->right = NULL;
        }
        free(current_node);
        return;
    }

    // If the node to delete has one child, we can replace the node to delete with its child
    if (current_node->left == NULL) {
        if (parent_node == NULL) {
            tree->root = current_node->right;
        } else if (parent_node->left == current_node) {
            parent_node->left = current_node->right;
        } else {
            parent_node->right = current_node->right;
        }
        free(current_node);
        return;
    } else if (current_node->right == NULL) {
        if (parent_node == NULL) {
            tree->root = current_node->left;
        } else if (parent_node->left == current_node) {
            parent_node->left = current_node->left;
        } else {
            parent_node->right = current_node->left;
        }
        free(current_node);
        return;
    }

    // If the node to delete has two children, we need to find the successor of the node to delete,
    // which is the smallest node in the right subtree of the node to delete
    struct node *successor_node = current_node->right;
    struct node *successor_parent_node = current_node;
    while (successor_node->left != NULL) {
        successor_parent_node = successor_node;
        successor_node = successor_node->left;
    }

    // Replace the data in the node to delete with the data in the successor node
    current_node->data = successor_node->data;

    // Delete the successor node
    if (successor_parent_node->left == successor_node) {
        successor_parent_node->left = successor_node->right;
    } else {
        successor_parent_node->right = successor_node->right;
    }
    free(successor_node);
}

// Print a binary search tree in order
void print_tree(struct tree *tree) {
    struct node *current_node = tree->root;

    if (current_node == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->left;
    }

    printf("\n");
}

// Free the memory used by a binary search tree
void free_tree(struct tree *tree) {
    struct node *current_node = tree->root;

    if (current_node == NULL) {
        return;
    }

    while (current_node != NULL) {
        struct node *next_node = current_node->right;
        free(current_node);
        current_node = next_node;
    }

    free(tree);
}

int main() {
    // Create a new binary search tree
    struct tree *tree = create_tree();

    // Insert some data into the tree
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 2);
    insert(tree, 7);
    insert(tree, 12);
    insert(tree, 20);

    // Print the tree
    printf("The tree is:\n");
    print_tree(tree);

    // Search for a node in the tree
    struct node *node = search(tree, 12);
    if (node != NULL) {
        printf("The node with data 12 was found.\n");
    } else {
        printf("The node with data 12 was not found.\n");
    }

    // Delete a node from the tree
    delete(tree, 10);

    // Print the tree
    printf("The tree after deleting the node with data 10 is:\n");
    print_tree(tree);

    // Free the memory used by the tree
    free_tree(tree);

    return 0;
}