//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for the tree node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} TreeNode;

// A function to create a new tree node with the given data value
TreeNode* newNode(int data) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// A function to insert a new node into the binary tree
void insert(TreeNode** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

// A function to print out the binary tree in ascending order
void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// The main function to create and print a binary tree
int main() {
    // Create an empty tree
    TreeNode* root = NULL;

    // Insert some nodes into the tree
    insert(&root, 10);
    insert(&root, 21);
    insert(&root, 4);
    insert(&root, 16);
    insert(&root, 8);
    insert(&root, 32);
    insert(&root, 2);
    insert(&root, 19);

    // Print out the contents of the tree in ascending order
    printf("Binary Tree Contents: ");
    printInOrder(root);
    printf("\n");

    // Clean up the memory used by the tree nodes
    free(root->left->left->left);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}