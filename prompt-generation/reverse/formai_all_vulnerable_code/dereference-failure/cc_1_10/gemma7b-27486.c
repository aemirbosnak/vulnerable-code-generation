//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node) {
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void printTree(Node* node) {
    printf("Inorder:");
    inorder(node);
    printf("\n");

    printf("Preorder:");
    preorder(node);
    printf("\n");
}

int main() {
    Node* root = NULL;
    root = malloc(sizeof(Node));
    root->data = 'A';
    root->left = malloc(sizeof(Node));
    root->left->data = 'B';
    root->right = malloc(sizeof(Node));
    root->right->data = 'C';

    printTree(root);

    return 0;
}