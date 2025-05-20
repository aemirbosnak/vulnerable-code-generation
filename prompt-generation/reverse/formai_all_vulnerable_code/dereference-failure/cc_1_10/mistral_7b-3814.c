//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

Node* search(Node* node, int key) {
    if (node == NULL || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);

    return search(node->right, key);
}

void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("BST: ");
    inorder(root);
    printf("\n");

    int searchKey;
    printf("\nEnter the key to search: ");
    scanf("%d", &searchKey);

    Node* searchResult = search(root, searchKey);

    if (searchResult != NULL)
        printf("\nKey %d found!", searchKey);
    else
        printf("\nKey %d not found!", searchKey);

    return 0;
}