//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define our nodes
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a new node into the tree
struct node *insert(struct node *node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    // Return unchanged node pointer
    return node;
}

// Do a inorder tree traversal and print out the nodes
void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d \n", root->key);
        inorder_traversal(root->right);
    }
}

// Main function
int main() {
    struct node *root = NULL;
    root = insert(root, 7);
    insert(root, 3);
    insert(root, 9);
    insert(root, 2);
    insert(root, 4);
    insert(root, 8);
    insert(root, 10);

    printf("Inorder traversal of the binary search tree:\n");
    inorder_traversal(root);

    return 0;
}