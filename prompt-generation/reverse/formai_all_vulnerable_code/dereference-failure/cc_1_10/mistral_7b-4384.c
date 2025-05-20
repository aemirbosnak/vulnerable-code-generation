//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char symbol;
    struct Node *left;
    struct Node *right;
} Node;

void printNode(Node *node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    if (node->left == NULL && node->right == NULL) {
        printf("%d%c\n", node->data, node->symbol);
    } else {
        printf("%d%c/\n", node->data, node->symbol);
        printNode(node->left, depth + 1);
        printNode(node->right, depth + 1);
    }
}

Node* createNode(int data, char symbol) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node *root = createNode(5, '*');
    root->left = createNode(3, '+');
    root->right = createNode(8, '+');
    root->left->left = createNode(2, '-');
    root->left->right = createNode(4, '-');
    root->right->left = createNode(6, '-');
    root->right->right = createNode(9, '-');

    printNode(root, 0);

    return 0;
}