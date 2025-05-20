//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given data
node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary tree
void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Print the binary tree in preorder traversal
void preorder_traversal(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print the binary tree in inorder traversal
void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print the binary tree in postorder traversal
void postorder_traversal(node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Find the minimum value in the binary tree
int find_min(node *root) {
    if (root->left == NULL) {
        return root->data;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in the binary tree
int find_max(node *root) {
    if (root->right == NULL) {
        return root->data;
    } else {
        return find_max(root->right);
    }
}

// Find the height of the binary tree
int find_height(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Check if the binary tree is a binary search tree
int is_bst(node *root) {
    if (root == NULL) {
        return 1;
    } else if (root->left != NULL && root->left->data > root->data) {
        return 0;
    } else if (root->right != NULL && root->right->data < root->data) {
        return 0;
    } else {
        return is_bst(root->left) && is_bst(root->right);
    }
}

// Delete the binary tree
void delete_tree(node *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a binary tree
    node *root = NULL;
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 70);
    insert_node(&root, 60);
    insert_node(&root, 80);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Find the minimum value in the binary tree
    printf("Minimum value: %d\n", find_min(root));

    // Find the maximum value in the binary tree
    printf("Maximum value: %d\n", find_max(root));

    // Find the height of the binary tree
    printf("Height: %d\n", find_height(root));

    // Check if the binary tree is a binary search tree
    printf("Is BST: %d\n", is_bst(root));

    // Delete the binary tree
    delete_tree(root);

    return 0;
}