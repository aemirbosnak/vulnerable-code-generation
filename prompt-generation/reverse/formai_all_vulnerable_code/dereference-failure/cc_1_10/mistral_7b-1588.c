//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[20];
    int height;
    struct Node *left, *right;
} Node;

Node *newNode(char *str) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->key, str);
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int balFactor(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *insert(Node *node, char *str) {
    if (node == NULL) {
        node = newNode(str);
        return node;
    }

    if (strcmp(str, node->key) < 0)
        node->left = insert(node->left, str);
    else if (strcmp(str, node->key) > 0)
        node->right = insert(node->right, str);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balFactor(node);

    if (balance > 1) {
        node = (balFactor(node->left) < 0)
               ? rightRotate(node)
               : balance > 1 ? leftRotate(node->left) : node;
    }

    return node;
}

void printTree(Node *node, int space) {
    if (node == NULL)
        return;

    space += 10;

    printTree(node->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", node->key);

    printTree(node->left, space);
}

int main(int argc, char **argv) {
    Node *root = NULL;

    if (argc < 2) {
        printf("Usage: %s <space_between_nodes> <key1 key2 key3 ...>\n",
               argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *str = argv[i];
        root = insert(root, str);
    }

    printTree(root, 0);

    return 0;
}