//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a node
struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search a node
struct node* searchNode(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print a node
void printNode(struct node* root) {
    if (root == NULL) {
        printf("Node is NULL\n");
        return;
    }
    printf("%d ", root->data);
    printNode(root->left);
    printNode(root->right);
}

// Main function
int main() {
    struct node* root = NULL;

    // Inserting nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root, 90);

    // Printing the tree
    printf("Binary Search Tree: \n");
    printNode(root);
    printf("\n");

    // Searching node
    struct node* found = searchNode(root, 70);
    if (found!= NULL) {
        printf("Node found: %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}