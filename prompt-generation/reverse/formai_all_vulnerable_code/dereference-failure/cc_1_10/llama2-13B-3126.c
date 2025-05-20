//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Definition of a peaceful tree node
typedef struct {
    int value;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new peaceful tree
node_t* new_tree(int value) {
    node_t* root = malloc(sizeof(node_t));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// Function to traverse the peaceful tree
void traverse(node_t* root) {
    if (root == NULL) {
        return;
    }

    // Print the value of the current node
    printf("%d ", root->value);

    // Traverse the left subtree
    traverse(root->left);

    // Traverse the right subtree
    traverse(root->right);
}

// Example usage of the peaceful tree
int main() {
    node_t* root = new_tree(1);

    // Create a left subtree with value 2
    root->left = new_tree(2);

    // Create a right subtree with value 3
    root->right = new_tree(3);

    // Traverse the peaceful tree
    traverse(root);

    return 0;
}