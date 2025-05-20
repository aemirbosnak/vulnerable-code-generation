//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: detailed
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
struct bst *create_bst() {
    struct bst *tree = malloc(sizeof(struct bst));
    tree->root = NULL;
    return tree;
}

// Insert a new node into a binary search tree
void insert_node(struct bst *tree, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    struct node *current_node = tree->root;
    while (1) {
        if (data < current_node->data) {
            if (current_node->left == NULL) {
                current_node->left = new_node;
                return;
            } else {
                current_node = current_node->left;
            }
        } else {
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
struct node *search_node(struct bst *tree, int data) {
    struct node *current_node = tree->root;

    while (current_node != NULL) {
        if (data == current_node->data) {
            return current_node;
        } else if (data < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    return NULL;
}

// Delete a node from a binary search tree
void delete_node(struct bst *tree, int data) {
    struct node *current_node = tree->root;
    struct node *parent_node = NULL;

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

    if (current_node == NULL) {
        return;
    }

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
    }

    if (current_node->right == NULL) {
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

    struct node *successor_node = current_node->right;
    struct node *successor_parent_node = current_node;

    while (successor_node->left != NULL) {
        successor_parent_node = successor_node;
        successor_node = successor_node->left;
    }

    current_node->data = successor_node->data;

    if (successor_node->right == NULL) {
        if (successor_parent_node == current_node) {
            successor_parent_node->right = NULL;
        } else {
            successor_parent_node->left = NULL;
        }
        free(successor_node);
        return;
    }

    successor_parent_node->left = successor_node->right;
    free(successor_node);
}

// Print a binary search tree in preorder
void preorder(struct node *node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Print a binary search tree in inorder
void inorder(struct node *node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Print a binary search tree in postorder
void postorder(struct node *node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Main function
int main() {
    // Create a binary search tree
    struct bst *tree = create_bst();

    // Insert some nodes into the binary search tree
    insert_node(tree, 10);
    insert_node(tree, 5);
    insert_node(tree, 15);
    insert_node(tree, 2);
    insert_node(tree, 7);
    insert_node(tree, 12);
    insert_node(tree, 20);

    // Print the binary search tree in preorder
    printf("Preorder: ");
    preorder(tree->root);
    printf("\n");

    // Print the binary search tree in inorder
    printf("Inorder: ");
    inorder(tree->root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Postorder: ");
    postorder(tree->root);
    printf("\n");

    // Search for a node in the binary search tree
    struct node *node = search_node(tree, 10);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the binary search tree
    delete_node(tree, 10);

    // Print the binary search tree in preorder
    printf("Preorder after deletion: ");
    preorder(tree->root);
    printf("\n");

    // Free the binary search tree
    free(tree);

    return 0;
}