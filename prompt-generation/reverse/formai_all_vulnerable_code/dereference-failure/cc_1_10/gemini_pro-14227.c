//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
node *insert_node(node *root, int data) {
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
node *find_min(node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in a binary search tree
node *find_max(node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Find the height of a binary search tree
int find_height(node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Print a binary search tree in order
void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Print a binary search tree in preorder
void print_preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

// Print a binary search tree in postorder
void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
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
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the binary search tree in order
    printf("In order: ");
    print_inorder(root);
    printf("\n");

    // Print the binary search tree in preorder
    printf("Pre order: ");
    print_preorder(root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Post order: ");
    print_postorder(root);
    printf("\n");

    // Find the minimum value in the binary search tree
    node *min_node = find_min(root);
    printf("Minimum value: %d\n", min_node->data);

    // Find the maximum value in the binary search tree
    node *max_node = find_max(root);
    printf("Maximum value: %d\n", max_node->data);

    // Find the height of the binary search tree
    int height = find_height(root);
    printf("Height: %d\n", height);

    // Free the binary search tree
    free_tree(root);

    return 0;
}