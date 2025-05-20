//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// A binary search tree (BST) is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.
// Each node stores a key-value pair, and the keys are arranged in a specific order.
// In a BST, the key of a node is always greater than the keys of its left children and less than the keys of its right children.

// The following code implements a BST in C.
// The BST is represented using a struct called `node`, which contains a pointer to the left child, a pointer to the right child, and a key-value pair.

typedef struct node {
    struct node *left;
    struct node *right;
    int key;
    int value;
} node_t;

// The following function creates a new node with the given key-value pair.
node_t *create_node(int key, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;
    new_node->value = value;
    return new_node;
}

// The following function inserts a new node into the BST.
void insert_node(node_t **root, node_t *new_node) {
    if (*root == NULL) {
        *root = new_node;
    } else if (new_node->key < (*root)->key) {
        insert_node(&(*root)->left, new_node);
    } else {
        insert_node(&(*root)->right, new_node);
    }
}

// The following function searches for a node with the given key in the BST.
node_t *search_node(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (root->key == key) {
        return root;
    } else if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

// The following function prints the keys of the nodes in the BST in ascending order.
void print_bst(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_bst(root->left);
    printf("%d ", root->key);
    print_bst(root->right);
}

// The following function frees the memory allocated for the BST.
void free_bst(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_bst(root->left);
    free_bst(root->right);
    free(root);
}

// The following is a test function that creates a BST and inserts some nodes into it.
// The function then prints the keys of the nodes in the BST in ascending order.
int main() {
    node_t *root = NULL;
    insert_node(&root, create_node(10, 10));
    insert_node(&root, create_node(5, 5));
    insert_node(&root, create_node(15, 15));
    insert_node(&root, create_node(2, 2));
    insert_node(&root, create_node(7, 7));
    insert_node(&root, create_node(12, 12));
    insert_node(&root, create_node(20, 20));
    print_bst(root);
    printf("\n");
    free_bst(root);
    return 0;
}