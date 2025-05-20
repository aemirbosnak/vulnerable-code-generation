//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Node of a binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert_node(&(*root)->right, data);
    }
}

// Search for a node in a binary search tree
node_t *search_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    }
}

// Print a binary search tree in preorder traversal
void preorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Print a binary search tree in inorder traversal
void inorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Print a binary search tree in postorder traversal
void postorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// Destroy a binary search tree
void destroy_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int main() {
    // Create a binary search tree
    node_t *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Search for a node in the binary search tree
    node_t *found_node = search_node(root, 12);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Destroy the binary search tree
    destroy_tree(root);

    return 0;
}