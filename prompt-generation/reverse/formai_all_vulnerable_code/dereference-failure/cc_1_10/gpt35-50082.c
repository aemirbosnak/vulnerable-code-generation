//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Recursive function to print binary tree using inorder traversal
void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Recursive function to insert a new node in a binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

int main() {
    // Create a binary tree
    struct Node* root = NULL;
    
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the binary tree using inorder traversal
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");

    return 0;
}