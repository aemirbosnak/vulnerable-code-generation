//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Define the node structure
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

// Function to search for a node in the tree
Node* searchNode(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

// Function to delete a node from the tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            root = temp;
            temp = temp->left;
        }
        root->key = temp->key;
        free(temp);
    }
    return root;
}

// Function to traverse and print the tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to destroy the tree
void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    // Insert nodes into the tree
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 17);

    // Print the tree using inorder traversal
    inorderTraversal(root);
    printf("\n");

    // Delete a node and print the tree again
    root = deleteNode(root, 5);
    inorderTraversal(root);
    printf("\n");

    // Destroy the tree
    destroyTree(root);

    return 0;
}