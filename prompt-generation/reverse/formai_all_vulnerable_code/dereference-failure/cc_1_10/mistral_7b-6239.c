//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[30];
    int height;
    struct Node *left, *right;
} Node;

Node* createNode(char key[]) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->height = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(Node* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, char key[]) {
    if (node == NULL)
        return createNode(key);

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getHeight(node->left) - getHeight(node->right);

    if (balance > 1) {
        if (height(node->left->left) >= height(node->left->right))
            node = rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    }

    return node;
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%s ", node->key);
        inorderTraversal(node->right);
    }
}

int main() {
    Node* root = NULL;

    char keys[20][30] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "mango", "peach", "pear", "persimmon", "pineapple", "plum", "quince", "strawberry", "tangerine", "watermelon", "yellowapples"};

    for (int i = 0; i < 18; i++)
        root = insert(root, keys[i]);

    printf("Inorder traversal of the created tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}