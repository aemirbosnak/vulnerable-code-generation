//FormAI DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define structure for Binary Search Tree node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new node
struct BSTNode* newNode(int data) {
    struct BSTNode* newNode = malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in BST
struct BSTNode* insertNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to search for a node in BST
int searchNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else {
        if (data < root->data) {
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }
    }
}

// Function to traverse BST in inorder manner
void inorderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to delete node from BST
struct BSTNode* deleteNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    struct BSTNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("Inorder traversal of the Binary Search Tree: \n");
    inorderTraversal(root);
    printf("\n");
    int dataToDelete = 60;
    root = deleteNode(root, dataToDelete);
    printf("Inorder traversal of the Binary Search Tree after deleting %d: \n", dataToDelete);
    inorderTraversal(root);
    return 0;
}