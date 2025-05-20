//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int height(Node* root) {
    if (root == NULL)
        return -1;
    else
        return max(height(root->left), height(root->right)) + 1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    Node* root = NULL;

    int arr[] = {15, 10, 20, 25, 8, 12, 17, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
        root = insert(root, arr[i]);

    printf("Inorder traversal of the Binary Search Tree: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Height of the Binary Search Tree: %d\n", height(root));

    return 0;
}