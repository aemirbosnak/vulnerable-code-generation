//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for our binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into the binary tree
Node* insert(Node* root, int data) {
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

// Function to print the binary tree in preorder traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to print the binary tree in postorder traversal
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Function to print the binary tree in inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function to test the binary tree implementation
int main() {
    Node* root = NULL;

    // Insert data into the binary tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}