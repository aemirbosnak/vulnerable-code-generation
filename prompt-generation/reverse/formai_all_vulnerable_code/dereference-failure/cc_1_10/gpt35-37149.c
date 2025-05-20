//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary tree using binary search
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test the binary search tree implementation
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal of binary search tree:\n");
    inorderTraversal(root);
    printf("\n");
    
    int searchData = 40;
    Node* searchResult = search(root, searchData);
    if (searchResult != NULL) {
        printf("%d found in the binary search tree.\n", searchData);
    }
    else {
        printf("%d not found in the binary search tree.\n", searchData);
    }
    
    searchData = 100;
    searchResult = search(root, searchData);
    if (searchResult != NULL) {
        printf("%d found in the binary search tree.\n", searchData);
    }
    else {
        printf("%d not found in the binary search tree.\n", searchData);
    }
    
    return 0;
}