//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100

typedef struct Node {
    char key[MAX_KEY_LENGTH];
    int height;
    struct Node *left, *right;
} Node;

Node* newNode(char* key) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->key, key);
    node->height = 0;
    node->left = node->right = NULL;
    return node;
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

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, char* key) {
    if (node == NULL) {
        node = newNode(key);
        return node;
    }

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        node = (getBalance(node->left) < 0)
               ? rightRotate(node)
               : (node->left->height > node->right->height)
                 ? leftRotate(node->left)
                 : rightRotate(node);
    }

    return node;
}

void inorder(Node* root, char output[10000]) {
    if (root != NULL) {
        inorder(root->left, output);
        strcat(output, root->key);
        strcat(output, " ");
        inorder(root->right, output);
    }
}

int main() {
    Node* root = NULL;

    char keys[10][MAX_KEY_LENGTH] = {"apple", "banana", "cherry", "date",
                                      "elderberry", "fig", "grape", "honeydew", "kiwi"};

    for (int i = 0; i < 10; i++)
        root = insert(root, keys[i]);

    char result[10000];
    inorder(root, result);

    printf("Inorder traversal: %s\n", result);

    return 0;
}