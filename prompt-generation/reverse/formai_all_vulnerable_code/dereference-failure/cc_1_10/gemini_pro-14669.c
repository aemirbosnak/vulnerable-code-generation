//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Search for a node in a binary search tree
struct node* search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print a binary search tree in order
void print_tree_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_inorder(root->left);
    printf("%d ", root->data);
    print_tree_inorder(root->right);
}

// Print a binary search tree in preorder
void print_tree_preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

// Print a binary search tree in postorder
void print_tree_postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    printf("%d ", root->data);
}

// Free a binary search tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Search for a node in the binary search tree
    struct node *found_node = search_node(root, 15);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    // Print the binary search tree in order
    printf("In order: ");
    print_tree_inorder(root);
    printf("\n");

    // Print the binary search tree in preorder
    printf("Pre order: ");
    print_tree_preorder(root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Post order: ");
    print_tree_postorder(root);
    printf("\n");

    // Free the binary search tree
    free_tree(root);

    return 0;
}