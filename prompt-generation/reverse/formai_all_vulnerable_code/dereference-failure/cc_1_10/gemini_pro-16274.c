//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

int searchNode(struct Node *root, int data) {
    if (root == NULL) {
        return 0;
    } else {
        if (root->data == data) {
            return 1;
        } else if (data <= root->data) {
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }
    }
}

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int data = 15;
    if (searchNode(root, data)) {
        printf("The data %d is found in the tree.\n", data);
    } else {
        printf("The data %d is not found in the tree.\n", data);
    }

    return 0;
}