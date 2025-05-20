//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    char name[50];
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void fixHeight(Node* N) {
    N->height = 1 + max(height(N->left), height(N->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    fixHeight(y);
    fixHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    fixHeight(x);
    fixHeight(y);

    return y;
}

Node* insert(Node* node, char* name) {
    if (node == NULL) {
        node = createNode(name);
        return node;
    }

    if (strcmp(name, node->name) < 0)
        node->left = insert(node->left, name);
    else if (strcmp(name, node->name) > 0)
        node->right = insert(node->right, name);

    fixHeight(node);
    return node;
}

void inorderTraversal(Node* node, char result[1000]) {
    if (node == NULL)
        return;

    inorderTraversal(node->left, result);
    strcat(result, node->name);
    strcat(result, " ");
    inorderTraversal(node->right, result);
}

void printTree(Node* node) {
    char result[1000] = {0};
    inorderTraversal(node, result);
    printf("\n%s\n", result);
}

int main() {
    Node* root = NULL;

    root = insert(root, "Elephant");
    root = insert(root, "Giraffe");
    root = insert(root, "Zebra");
    root = insert(root, "Lion");
    root = insert(root, "Tiger");
    root = insert(root, "Rhinoceros");
    root = insert(root, "Hippopotamus");
    root = insert(root, "Crocodile");

    printTree(root);

    return 0;
}