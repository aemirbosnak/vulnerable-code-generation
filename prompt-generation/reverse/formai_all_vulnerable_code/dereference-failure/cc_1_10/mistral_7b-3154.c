//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

bool search(Node* node, int key) {
    if (node == NULL) {
        return false;
    }

    if (key < node->key) {
        return search(node->left, key);
    } else if (key > node->key) {
        return search(node->right, key);
    } else {
        return true;
    }
}

void inOrderTraversal(Node* node, void(*func)(int)) {
    if (node == NULL) {
        return;
    }

    inOrderTraversal(node->left, func);
    func(node->key);
    inOrderTraversal(node->right, func);
}

void randomizeArray(int* arr, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    int* arr = (int*) malloc(size * sizeof(int));
    randomizeArray(arr, size);
    printArray(arr, size);

    Node* root = NULL;

    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    printf("BST:\n");
    inOrderTraversal(root, printf);

    int searchKey;
    printf("Enter the number to search: ");
    scanf("%d", &searchKey);

    if (search(root, searchKey)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    free(arr);
    free(root);

    return 0;
}