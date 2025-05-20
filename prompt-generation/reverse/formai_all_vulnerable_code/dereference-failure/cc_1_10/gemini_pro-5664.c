//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

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

void inorderTraversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

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

int main() {
    node *root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the binary search tree:\n");
    inorderTraversal(root);
    printf("\n");

    int data = 40;
    node *foundNode = searchNode(root, data);
    if (foundNode != NULL) {
        printf("The node with data %d was found in the binary search tree.\n", data);
    } else {
        printf("The node with data %d was not found in the binary search tree.\n", data);
    }

    return 0;
}