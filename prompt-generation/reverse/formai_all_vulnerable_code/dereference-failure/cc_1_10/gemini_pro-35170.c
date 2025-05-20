//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Node structure
typedef struct node_t {
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Find the minimum value in a binary search tree
node_t *find_min(node_t *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find the maximum value in a binary search tree
node_t *find_max(node_t *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Find the successor of a node in a binary search tree
node_t *find_successor(node_t *root, int data) {
    node_t *current = root;
    node_t *successor = NULL;
    while (current != NULL) {
        if (data < current->data) {
            successor = current;
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            if (current->right != NULL) {
                successor = find_min(current->right);
            }
            break;
        }
    }
    return successor;
}

// Find the predecessor of a node in a binary search tree
node_t *find_predecessor(node_t *root, int data) {
    node_t *current = root;
    node_t *predecessor = NULL;
    while (current != NULL) {
        if (data > current->data) {
            predecessor = current;
            current = current->right;
        } else if (data < current->data) {
            current = current->left;
        } else {
            if (current->left != NULL) {
                predecessor = find_max(current->left);
            }
            break;
        }
    }
    return predecessor;
}

// Delete a node from a binary search tree
node_t *delete_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            node_t *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            node_t *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Node has two children
        else {
            node_t *successor = find_successor(root->right, root->data);
            root->data = successor->data;
            root->right = delete_node(root->right, successor->data);
        }
    }
    return root;
}

// Print a binary search tree
void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Main function
int main() {
    // Create a binary search tree
    node_t *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the binary search tree
    printf("Binary search tree: ");
    print_tree(root);
    printf("\n");

    // Find the minimum value in the binary search tree
    node_t *min = find_min(root);
    printf("Minimum value: %d\n", min->data);

    // Find the maximum value in the binary search tree
    node_t *max = find_max(root);
    printf("Maximum value: %d\n", max->data);

    // Find the successor of a node in the binary search tree
    node_t *successor = find_successor(root, 30);
    printf("Successor of 30: %d\n", successor->data);

    // Find the predecessor of a node in the binary search tree
    node_t *predecessor = find_predecessor(root, 30);
    printf("Predecessor of 30: %d\n", predecessor->data);

    // Delete a node from the binary search tree
    root = delete_node(root, 30);

    // Print the binary search tree
    printf("Binary search tree after deleting 30: ");
    print_tree(root);
    printf("\n");

    return 0;
}