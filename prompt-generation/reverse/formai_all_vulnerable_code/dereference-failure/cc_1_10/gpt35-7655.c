//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
/* Protected style implementation of a binary tree data structure visualization. */

#include <stdio.h>
#include <stdlib.h>

/* Define the data structure of a tree node. */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node with the given data and NULL left and right nodes. */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert a new node into the tree at the appropriate location. */
struct node* insertNode(struct node* root, int data) {
    if (root == NULL) { // Base case: create new node if the tree is empty.
        return createNode(data);
    }
    if (data < root->data) { // Recursively insert into the left subtree.
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) { // Recursively insert into the right subtree.
        root->right = insertNode(root->right, data);
    }
    return root; // Return the updated tree.
}

/* Recursive preorder traversal for visualization. */
void preorderTraversal(struct node* root, int level) {
    if (root != NULL) {
        printf("%*s%d\n", level*4, "", root->data); // Print the current node's data.
        preorderTraversal(root->left, level+1); // Traverse the left subtree.
        preorderTraversal(root->right, level+1); // Traverse the right subtree.
    }
}

int main() {
    struct node* root = NULL;
    int choice = 1;
    int data;

    printf("Please enter some integers to add to the binary tree.\n(Enter 0 to stop.)\n");
    while (choice != 0) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("\nBinary tree visualization:\n");
    preorderTraversal(root, 0);

    return 0;
}