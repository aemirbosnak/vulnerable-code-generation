//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node *newNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to insert a node into binary tree
Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in a binary tree
Node *minValueNode(Node *node) {
    Node *curr = node;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

// Function to delete a node from binary tree
Node *deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: get inorder successor (smallest in the right subtree)
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print inorder traversal of binary tree
void printInorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Main function
int main() {
    Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Binary search tree before deletion:\n");
    printInorder(root);

    root = deleteNode(root, 20);

    printf("\n\nBinary search tree after deletion of 20:\n");
    printInorder(root);

    root = deleteNode(root, 30);

    printf("\n\nBinary search tree after deletion of 30:\n");
    printInorder(root);

    root = deleteNode(root, 50);

    printf("\n\nBinary search tree after deletion of 50:\n");
    printInorder(root);

    return 0;
}