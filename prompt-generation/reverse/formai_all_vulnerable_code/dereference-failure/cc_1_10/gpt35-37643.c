//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
/*
* Binary search tree example program:
* Creates a BST of even numbers and performs mathematical operations on it.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform the mathematical operation of addition on BST
int addBST(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + addBST(root->left) + addBST(root->right);
}

// Function to perform the mathematical operation of multiplication on BST
int multiplyBST(struct node* root) {
    if (root == NULL) {
        return 1;
    }
    return root->data * multiplyBST(root->left) * multiplyBST(root->right);
}

// Function to perform the mathematical operation of finding the maximum value in BST
int findMax(struct node* root) {
    if (root == NULL) {
        printf("\nBST is empty.\n");
        return -1;
    }
    if (root->right == NULL) {
        return root->data;
    }
    return findMax(root->right);
}

// Function to perform the mathematical operation of finding the minimum value in BST
int findMin(struct node* root) {
    if (root == NULL) {
        printf("\nBST is empty.\n");
        return -1;
    }
    if (root->left == NULL) {
        return root->data;
    }
    return findMin(root->left);
}

// Main method
int main() {
    struct node* root = NULL;
    root = insert(root, 8);
    insert(root, 2);
    insert(root, 12);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    printf("Sum of all nodes in BST = %d\n", addBST(root));
    printf("Product of all nodes in BST = %d\n", multiplyBST(root));
    printf("Maximum value in BST = %d\n", findMax(root));
    printf("Minimum value in BST = %d\n", findMin(root));

    return 0;
}