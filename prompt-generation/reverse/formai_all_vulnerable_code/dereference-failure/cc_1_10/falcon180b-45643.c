//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a value in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Function to print the inorder traversal of the tree
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program to test above functions
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree is: \n");
    inorder(root);

    int searchKey = 40;
    struct node* result = search(root, searchKey);

    if (result!= NULL)
        printf("\n%d found in the tree", searchKey);
    else
        printf("\n%d not found in the tree", searchKey);

    return 0;
}