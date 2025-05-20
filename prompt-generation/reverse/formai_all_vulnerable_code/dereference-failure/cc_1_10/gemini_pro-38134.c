//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

// Define the data structure for a node in the binary search tree.
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Define the data structure for the binary search tree.
struct tree {
    struct node *root;
};

// Create a new node with the given data.
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary search tree.
void insert(struct tree *tree, int data) {
    struct node *new_node = create_node(data);

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct node *current_node = tree->root;
        while (1) {
            if (data < current_node->data) {
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

// Search for the given data in the binary search tree.
struct node *search(struct tree *tree, int data) {
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

// Print the data in the binary search tree in ascending order.
void print_tree(struct tree *tree) {
    struct node *current_node = tree->root;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        if (current_node->left != NULL) {
            current_node = current_node->left;
        } else {
            while (current_node->right == NULL) {
                current_node = current_node->right;
            }
            current_node = current_node->right;
        }
    }
}

// Free the memory allocated for the binary search tree.
void free_tree(struct tree *tree) {
    struct node *current_node = tree->root;

    while (current_node != NULL) {
        struct node *next_node = NULL;
        if (current_node->left != NULL) {
            next_node = current_node->left;
        } else if (current_node->right != NULL) {
            next_node = current_node->right;
        }
        free(current_node);
        current_node = next_node;
    }
}

// Main function.
int main() {
    // Create a new binary search tree.
    struct tree *tree = malloc(sizeof(struct tree));
    tree->root = NULL;

    // Insert some data into the binary search tree.
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 2);
    insert(tree, 7);
    insert(tree, 12);
    insert(tree, 20);

    // Search for the data in the binary search tree.
    struct node *node = search(tree, 15);
    if (node != NULL) {
        printf("Found the data %d in the tree.\n", node->data);
    } else {
        printf("Could not find the data in the tree.\n");
    }

    // Print the data in the binary search tree in ascending order.
    printf("The data in the tree in ascending order is: ");
    print_tree(tree);
    printf("\n");

    // Free the memory allocated for the binary search tree.
    free_tree(tree);

    return 0;
}