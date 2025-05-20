//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A binary search tree
struct Tree {
    struct Node *root;
};

// Create a new binary search tree
struct Tree *create_tree() {
    struct Tree *tree = malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

// Insert a new node into a binary search tree
void insert_node(struct Tree *tree, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct Node *current = tree->root;
        while (1) {
            if (data < current->data) {
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

// Search for a node in a binary search tree
struct Node *search_node(struct Tree *tree, int data) {
    struct Node *current = tree->root;
    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

// Delete a node from a binary search tree
void delete_node(struct Tree *tree, int data) {
    struct Node *current = tree->root;
    struct Node *parent = NULL;
    while (current != NULL) {
        if (data == current->data) {
            break;
        } else if (data < current->data) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Node not found\n");
        return;
    }

    // Case 1: Node has no children
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            tree->root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }

    // Case 2: Node has one child
    else if (current->left == NULL) {
        if (parent == NULL) {
            tree->root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
    } else if (current->right == NULL) {
        if (parent == NULL) {
            tree->root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    }

    // Case 3: Node has two children
    else {
        struct Node *successor = current->right;
        struct Node *successor_parent = current;
        while (successor->left != NULL) {
            successor_parent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successor_parent == current) {
            successor_parent->right = successor->right;
        } else {
            successor_parent->left = successor->right;
        }
    }

    free(current);
}

// Print a binary search tree in preorder traversal
void preorder_traversal(struct Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

// Print a binary search tree in inorder traversal
void inorder_traversal(struct Node *node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

// Print a binary search tree in postorder traversal
void postorder_traversal(struct Node *node) {
    if (node != NULL) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printf("%d ", node->data);
    }
}

// Main function
int main() {
    struct Tree *tree = create_tree();

    insert_node(tree, 10);
    insert_node(tree, 5);
    insert_node(tree, 15);
    insert_node(tree, 2);
    insert_node(tree, 7);
    insert_node(tree, 12);
    insert_node(tree, 20);

    printf("Preorder traversal: ");
    preorder_traversal(tree->root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(tree->root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(tree->root);
    printf("\n");

    struct Node *node = search_node(tree, 7);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    delete_node(tree, 15);

    printf("Inorder traversal after deletion: ");
    inorder_traversal(tree->root);
    printf("\n");

    return 0;
}