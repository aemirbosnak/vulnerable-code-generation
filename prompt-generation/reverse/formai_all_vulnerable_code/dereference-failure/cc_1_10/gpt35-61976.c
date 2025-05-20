//FormAI DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node *insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the BST
Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root; 
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

// Function to traverse the BST in order
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    // Initialize the root node and insert some data
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Perform an inorder traversal to see if the nodes were inserted correctly
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    // Search for a node
    Node *searchResult = search(root, 40);
    if (searchResult == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found: %d\n", searchResult->data);
    }
    
    // Free the node memory
    free(root);
    
    return 0;
}