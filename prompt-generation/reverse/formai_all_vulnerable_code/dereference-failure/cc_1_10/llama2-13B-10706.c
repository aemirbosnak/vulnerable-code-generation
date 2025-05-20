//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Function to create a new tree node
struct TreeNode *newNode(int data) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insertNode(struct TreeNode **root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data <= (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

// Function to traverse the tree
void traverse(struct TreeNode *root) {
    if (root != NULL) {
        printf("Current node is: %d\n", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

int main() {
    struct TreeNode *root = NULL;

    // Insert some nodes into the tree
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);

    // Traverse the tree
    traverse(root);

    return 0;
}