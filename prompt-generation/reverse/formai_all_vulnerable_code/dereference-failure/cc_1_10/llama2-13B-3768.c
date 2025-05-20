//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a binary tree node
typedef struct {
    int data;
    struct node *left, *right;
} node_t;

// Function to create a new node with the given data
node_t* new_node(int data) {
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the binary tree
void traverse(node_t* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverse(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    traverse(root->right);
}

// Function to build a binary tree from a string
node_t* build_tree(char* str) {
    node_t* root = NULL;
    char* token;

    // Tokenize the string into individual nodes
    while ((token = strtok(str, " ")) != NULL) {
        // Create a new node with the token value
        node_t* node = new_node(atoi(token));

        // Add the node to the tree
        if (root == NULL) {
            root = node;
        } else {
            if (token[0] == 'L') {
                root->left = node;
            } else {
                root->right = node;
            }
        }
    }

    return root;
}

int main() {
    // Build a binary tree from the string "1 2 3 L 4 R 5"
    char* str = "1 2 3 L 4 R 5";
    node_t* root = build_tree(str);

    // Traverse the binary tree
    traverse(root);

    return 0;
}