//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// function to create a new node
node* createNode(int val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a value in BST
node* insert(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// function to search a value in BST
int search(node* root, int val) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == val) {
        return 1;
    }
    else if (val < root->data) {
        return search(root->left, val);
    }
    else {
        return search(root->right, val);
    }
}

int main() {
    // Create an empty BST
    node* root = NULL;

    // insert some values in BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // search for a value in BST
    if(search(root, 30)) {
        printf("Found the value!\n");
    }
    else {
        printf("Value not found :(\n");
    }

    return 0;
}