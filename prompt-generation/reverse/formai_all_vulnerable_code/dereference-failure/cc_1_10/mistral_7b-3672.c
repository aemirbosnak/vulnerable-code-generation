//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        return searchNode(root->left, key);
    } else if (key > root->key) {
        return searchNode(root->right, key);
    } else {
        return root;
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 17);

    printf("Inorder traversal of the binary search tree:\n");
    inorderTraversal(root);

    Node* search = searchNode(root, 12);
    if (search != NULL) {
        printf("\nKey 12 found in the tree\n");
    } else {
        printf("\nKey 12 not found in the tree\n");
    }

    free(root);

    return 0;
}