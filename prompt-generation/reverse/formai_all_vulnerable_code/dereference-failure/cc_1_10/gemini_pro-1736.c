//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Insert a node into a binary search tree
struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node in a binary search tree
struct Node* search(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Print a binary search tree in order
void print_inorder(struct Node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

// Main function
int main() {
    // Create a binary search tree
    struct Node *root = NULL;

    // Insert some nodes into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Search for a node in the tree
    struct Node *found_node = search(root, 15);

    // Print the tree in order
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    // Free the memory allocated for the tree
    free(root);

    return 0;
}