//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Insert a node into a binary search tree
struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        // Create a new node
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        // Return the new node
        return new_node;
    }

    // Recursively insert the node into the left or right subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    // Return the root node
    return root;
}

// Search for a node in a binary search tree
struct Node* search(struct Node *root, int data) {
    if (root == NULL) {
        // Node not found
        return NULL;
    }

    if (data == root->data) {
        // Node found
        return root;
    }

    if (data < root->data) {
        // Search the left subtree
        return search(root->left, data);
    } else {
        // Search the right subtree
        return search(root->right, data);
    }
}

// Print the binary search tree in inorder
void inorder(struct Node *root) {
    if (root != NULL) {
        // Print the left subtree
        inorder(root->left);

        // Print the root node
        printf("%d ", root->data);

        // Print the right subtree
        inorder(root->right);
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

    if (found_node != NULL) {
        // Node found
        printf("Node found: %d\n", found_node->data);
    } else {
        // Node not found
        printf("Node not found\n");
    }

    // Print the tree in inorder
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}