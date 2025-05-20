//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void printTree(Node *node, int space) {
    if (node == NULL) {
        return;
    }

    printTree(node->right, space + 4);

    for (int i = 0; i < space; i++) {
        printf("  ");
    }

    printf("%d\n", node->data);

    printTree(node->left, space + 4);
}

int main() {
    Node *root = NULL;

    root = (Node *)malloc(sizeof(Node));
    root->data = 1;

    root->left = (Node *)malloc(sizeof(Node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = (Node *)malloc(sizeof(Node));
    root->left->right->data = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = (Node *)malloc(sizeof(Node));
    root->right->data = 4;
    root->right->left = NULL;
    root->right->right = (Node *)malloc(sizeof(Node));
    root->right->right->data = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    printTree(root, 0);

    return 0;
}