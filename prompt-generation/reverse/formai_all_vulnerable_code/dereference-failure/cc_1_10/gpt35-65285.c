//FormAI DATASET v1.0 Category: Binary search trees ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 20);

    printf("In order traversal: ");
    printInOrder(root);

    return 0;
}