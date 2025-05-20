//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Node struct
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Insert a node into a binary search tree
node *insert(node *root, int data) {
    if (root == NULL) {
        node *new_node = malloc(sizeof(node));
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
node *search(node *root, int data) {
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

// Print a binary search tree in preorder
void preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Print a binary search tree in inorder
void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Print a binary search tree in postorder
void postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Free a binary search tree
void free_tree(node *root) {
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
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search for a node in the binary search tree
    node *found_node = search(root, 40);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Print the binary search tree in preorder
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    // Print the binary search tree in inorder
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    // Free the binary search tree
    free_tree(root);

    return 0;
}