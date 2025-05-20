//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* A struct to represent the node in a binary tree */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* A function to create a new node in a binary tree */
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* A function to insert a new node into a binary tree */
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

/* A function to print the elements of a binary tree in sorted order */
void print_binary_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_binary_tree(root->left);
    printf("%d ", root->data);
    print_binary_tree(root->right);
}

/* A function to free the memory allocated to a binary tree */
void free_binary_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root);
}

/* A function to find the maximum depth of a binary tree */
int max_depth(struct node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);
        return fmax(left_depth, right_depth) + 1;
    }
}

/* A function to find the minimum depth of a binary tree */
int min_depth(struct node *root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        int left_depth = min_depth(root->left);
        int right_depth = min_depth(root->right);
        return fmin(left_depth, right_depth) + 1;
    }
}

/* A function to check if a binary tree is balanced */
int is_balanced(struct node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);
        return abs(left_depth - right_depth) <= 1 && is_balanced(root->left) && is_balanced(root->right);
    }
}

/* A function to check if a binary tree is a binary search tree */
int is_bst(struct node *root) {
    if (root == NULL) {
        return 1;
    } else if (root->left != NULL && root->left->data >= root->data) {
        return 0;
    } else if (root->right != NULL && root->right->data <= root->data) {
        return 0;
    } else {
        return is_bst(root->left) && is_bst(root->right);
    }
}

int main() {
    /* Create a binary tree */
    struct node *root = create_node(10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    /* Print the elements of the binary tree in sorted order */
    printf("Sorted elements: ");
    print_binary_tree(root);
    printf("\n");

    /* Print the maximum depth of the binary tree */
    printf("Maximum depth: %d\n", max_depth(root));

    /* Print the minimum depth of the binary tree */
    printf("Minimum depth: %d\n", min_depth(root));

    /* Check if the binary tree is balanced */
    printf("Is balanced: %d\n", is_balanced(root));

    /* Check if the binary tree is a binary search tree */
    printf("Is BST: %d\n", is_bst(root));

    /* Free the memory allocated to the binary tree */
    free_binary_tree(root);

    return 0;
}