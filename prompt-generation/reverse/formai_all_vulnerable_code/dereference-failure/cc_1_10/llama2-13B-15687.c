//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a tree node
typedef struct node {
    int data;
    struct node *left, *right;
} node_t;

// Define a function to create a new node
node_t* new_node(int data) {
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to insert a node into the tree
void insert_node(node_t** root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Define a function to print the tree
void print_tree(node_t* root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

// Define the recursive function to traverse the tree
void traverse(node_t* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    node_t* root = NULL;

    // Insert some nodes into the tree
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 3);
    insert_node(&root, 4);
    insert_node(&root, 5);

    // Print the tree
    print_tree(root);

    // Traverse the tree recursively
    traverse(root);

    return 0;
}