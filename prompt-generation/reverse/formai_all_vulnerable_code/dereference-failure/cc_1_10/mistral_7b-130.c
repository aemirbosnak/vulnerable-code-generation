//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inOrderTraversal(Node* root, void(*function)(int)) {
    if (root != NULL) {
        inOrderTraversal(root->left, function);
        function(root->key);
        inOrderTraversal(root->right, function);
    }
}

void printInt(int num) {
    printf("%d ", num);
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < size; i++) {
        root = insert(root, keys[i]);
    }

    printf("In Order Traversal: ");
    inOrderTraversal(root, printInt);

    return 0;
}