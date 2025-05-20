//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insert(&root, arr[i]);
    }

    printf("Inorder traversal of the binary tree: ");
    inOrderTraversal(root);

    return 0;
}