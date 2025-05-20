//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>

// Definition of a binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new binary tree node
struct node* newNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print preorder traversal of a binary tree
void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to print inorder traversal of a binary tree
void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to print postorder traversal of a binary tree
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create binary tree with given values
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    // Print preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    
    // Print inorder traversal
    printf("\nInorder traversal: ");
    inorder(root);
    
    // Print postorder traversal
    printf("\nPostorder traversal: ");
    postorder(root);
    
    return 0;
}