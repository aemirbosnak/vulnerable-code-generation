//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Struct for BST node
struct node {
    int key;
    struct node *left, *right;
};

// Function for creating a new node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function for inserting a node
struct node *insert(struct node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    return node;
}

// Function to print tree in inorder traversal
void printInorder(struct node *node) {
    if (node != NULL) {
        printInorder(node->left);
        printf("%d ", node->key);
        printInorder(node->right);
    }
}

// Function to print the tree
void printTree(struct node *root, int space) {
    if (root == NULL) return;

    // Increase distance between levels
    space += 5;

    // Print right child
    printTree(root->right, space);

    // Print current node after the spacing
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Create spaces for left child
    printTree(root->left, space);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the tree: \n");
    printInorder(root);

    printf("\n\n");
    printf("Visualization of the tree: \n\n");
    printTree(root, 0);

    return 0;
}