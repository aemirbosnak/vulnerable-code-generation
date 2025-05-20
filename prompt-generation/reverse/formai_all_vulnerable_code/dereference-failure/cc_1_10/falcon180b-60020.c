//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the BST
struct node* insert(struct node* root, int data) {
    // If the root is null, assign a new node address to root
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged node pointer
    return root;
}

// Function to perform an inorder traversal of the BST
void inorder(struct node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Function to perform a preorder traversal of the BST
void preorder(struct node* node) {
    if (node!= NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Function to perform a postorder traversal of the BST
void postorder(struct node* node) {
    if (node!= NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    struct node* root = NULL;

    // Insert sample data into the BST
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);

    // Perform an inorder traversal and print the sorted data
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Perform a preorder traversal and print the sorted data
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Perform a postorder traversal and print the sorted data
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}