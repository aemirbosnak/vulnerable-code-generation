//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a tree node
struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

// Define a function to create a new tree node
struct tree_node* new_node(int data) {
    struct tree_node* node = (struct tree_node*) malloc(sizeof(struct tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to insert a node into the tree
void insert_node(struct tree_node** root, int data) {
    struct tree_node* node = new_node(data);
    if (*root == NULL) {
        *root = node;
    } else {
        if (data < (*root)->data) {
            (*root)->left = node;
        } else {
            (*root)->right = node;
        }
    }
}

// Define a function to print the tree
void print_tree(struct tree_node* root) {
    if (root != NULL) {
        printf("Tree: ");
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    struct tree_node* root = NULL;

    // Insert nodes into the tree
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 8);
    insert_node(&root, 3);
    insert_node(&root, 6);

    // Print the tree
    print_tree(root);

    return 0;
}