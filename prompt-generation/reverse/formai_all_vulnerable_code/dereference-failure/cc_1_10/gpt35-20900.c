//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node of a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node of a binary tree
node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into a binary tree
node *insertNode(node *root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Function to print the elements of a binary tree in order traversal
void inorderTraversal(node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to print the elements of a binary tree in preorder traversal
void preorderTraversal(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to print the elements of a binary tree in postorder traversal
void postorderTraversal(node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to generate a binary tree with random values
node *generateTree() {
    node *root = NULL;
    int n = 10;
    while (n--) {
        int value = rand() % 100 + 1;
        root = insertNode(root, value);
    }
    return root;
}

int main() {
    // Generate a binary tree with random values
    node *root = generateTree();

    // Print the elements of the binary tree in various order traversals
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    free(root);
    return 0;
}