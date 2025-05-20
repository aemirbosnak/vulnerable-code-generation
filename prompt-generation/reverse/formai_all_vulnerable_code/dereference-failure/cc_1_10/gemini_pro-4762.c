//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure to store a node in a binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node in a binary search tree
node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a binary search tree
node *insertNode(node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in a binary search tree
node *searchNode(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print a binary search tree in preorder traversal
void preorderTraversal(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to print a binary search tree in inorder traversal
void inorderTraversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to print a binary search tree in postorder traversal
void postorderTraversal(node *root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Driver code to test the binary search tree functions
int main() {
    // Create a binary search tree
    node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Search for a node in the binary search tree
    node *foundNode = searchNode(root, 40);
    if (foundNode != NULL) {
        printf("Node found: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}