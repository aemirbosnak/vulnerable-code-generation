//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Node struct for binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Insert a node into a binary search tree
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node in a binary search tree
bool search(struct Node *root, int data) {
    if (root == NULL) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    }
}

// Print the data in a binary search tree in order
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Print the data in a binary search tree in preorder
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Print the data in a binary search tree in postorder
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free the memory allocated to a binary search tree
void free_tree(struct Node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a binary search tree
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the data in the binary search tree in order
    inorder(root);
    printf("\n");

    // Print the data in the binary search tree in preorder
    preorder(root);
    printf("\n");

    // Print the data in the binary search tree in postorder
    postorder(root);
    printf("\n");

    // Search for a node in the binary search tree
    if (search(root, 15)) {
        printf("15 found in the binary search tree\n");
    } else {
        printf("15 not found in the binary search tree\n");
    }

    // Free the memory allocated to the binary search tree
    free_tree(root);

    return 0;
}