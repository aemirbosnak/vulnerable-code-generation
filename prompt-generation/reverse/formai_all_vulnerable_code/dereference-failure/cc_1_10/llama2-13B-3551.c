//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a "tree"
struct tree {
    int data;
    struct tree *left, *right;
};

// Define a function to create a new tree
struct tree* new_tree(int data) {
    struct tree* t = malloc(sizeof(struct tree));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

// Define a function to free a tree
void free_tree(struct tree* t) {
    if (t == NULL) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

// Define a function to traverse a tree
void traverse(struct tree* t) {
    if (t == NULL) return;
    printf("Data: %d\n", t->data);
    traverse(t->left);
    traverse(t->right);
}

int main() {
    // Create a new tree
    struct tree* root = new_tree(10);

    // Create a new left child
    struct tree* left = new_tree(5);
    root->left = left;

    // Create a new right child
    struct tree* right = new_tree(15);
    root->right = right;

    // Traverse the tree
    traverse(root);

    // Free the tree
    free_tree(root);

    return 0;
}