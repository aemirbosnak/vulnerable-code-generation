//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the binary search tree node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Define the binary search tree function
struct Node* newNode(int data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define the binary search tree function
struct Node* insertNode(struct Node* root, int data) {
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

// Define the binary search tree function
struct Node* printInorder(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* left = printInorder(root->left);
    struct Node* node = root;
    struct Node* right = printInorder(root->right);
    printf("%d ", node->data);
    return node->right;
}

// Define the main function
int main() {
    struct Node* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    printf("Inorder traversal of the binary search tree is: ");
    printInorder(root);
    printf("\n");

    return 0;
}