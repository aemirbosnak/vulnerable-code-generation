//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct BST_node {
    int value;
    struct BST_node* left;
    struct BST_node* right;
};

// Insert a node into the binary search tree
void insert(struct BST_node** root, int value) {
    // If the root is null, create a new node and make it the root
    if (*root == NULL) {
        struct BST_node* new_node = (struct BST_node*) malloc(sizeof(struct BST_node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        *root = new_node;
    }
    // Otherwise, insert the node into the appropriate subtree
    else {
        if (value < (*root)->value) {
            insert(&((*root)->left), value);
        }
        else {
            insert(&((*root)->right), value);
        }
    }
}

// Print the binary search tree in order
void inorder_traversal(struct BST_node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

int main() {
    // Create a binary search tree and insert some nodes
    struct BST_node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    // Print the binary search tree
    printf("Binary Search Tree: ");
    inorder_traversal(root);
    printf("\n");

    // Free the memory of the binary search tree
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}