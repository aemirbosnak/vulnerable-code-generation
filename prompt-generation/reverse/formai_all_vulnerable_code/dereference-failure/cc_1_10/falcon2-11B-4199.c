//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct node {
    int key;
    struct node *left;
    struct node *right;
};

// Function to insert a new node with the given key in the BST
struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

// Function to search for a node with the given key in the BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the BST in inorder traversal
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    
    // Insert some nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Print the BST in inorder traversal
    printf("Inorder traversal of the BST:\n");
    inorder(root);
    
    // Search for a node with the given key
    printf("Searching for 30 in the BST:\n");
    struct node* found = search(root, 30);
    if (found!= NULL) {
        printf("Found!\n");
    } else {
        printf("Not found\n");
    }
    
    return 0;
}