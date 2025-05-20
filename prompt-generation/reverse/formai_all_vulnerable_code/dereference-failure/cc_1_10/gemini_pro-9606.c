//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Insert a value into a binary search tree
struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search for a value in a binary search tree
struct node* search(struct node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Print the values of a binary search tree in order
void print_inorder(struct node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->value);
        print_inorder(root->right);
    }
}

// Print the values of a binary search tree in preorder
void print_preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

// Print the values of a binary search tree in postorder
void print_postorder(struct node *root) {
    if (root != NULL) {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->value);
    }
}

// Free the memory used by a binary search tree
void free_tree(struct node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Search for a value in the binary search tree
    struct node *found = search(root, 12);
    if (found != NULL) {
        printf("Found the value %d in the binary search tree.\n", found->value);
    } else {
        printf("Could not find the value in the binary search tree.\n");
    }

    // Print the values of the binary search tree in order
    printf("Values in order:\n");
    print_inorder(root);
    printf("\n");

    // Print the values of the binary search tree in preorder
    printf("Values in preorder:\n");
    print_preorder(root);
    printf("\n");

    // Print the values of the binary search tree in postorder
    printf("Values in postorder:\n");
    print_postorder(root);
    printf("\n");

    // Free the memory used by the binary search tree
    free_tree(root);

    return 0;
}