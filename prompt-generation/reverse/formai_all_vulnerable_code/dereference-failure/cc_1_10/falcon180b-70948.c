//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with given data into the BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, return a new node
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

// Function to search for a node with given data in the BST
struct node* search(struct node* root, int data) {
    // If the tree is empty or the data is found, return the node
    if (root == NULL || root->data == data)
        return root;

    // If the data is smaller, recur down the left subtree
    if (data < root->data)
        return search(root->left, data);

    // Otherwise, recur down the right subtree
    return search(root->right, data);
}

// Function to print the inorder traversal of the BST
void printInorder(struct node* root) {
    if (root!= NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Main function
int main() {
    // Create the initial empty tree
    struct node* root = NULL;

    // Insert nodes with medieval names
    root = insert(root, 50);  // King Arthur
    root = insert(root, 25);  // Queen Guinevere
    root = insert(root, 75);  // Sir Lancelot
    root = insert(root, 100); // Merlin the Magician

    // Print the inorder traversal of the tree
    printf("Inorder traversal:\n");
    printInorder(root);

    return 0;
}