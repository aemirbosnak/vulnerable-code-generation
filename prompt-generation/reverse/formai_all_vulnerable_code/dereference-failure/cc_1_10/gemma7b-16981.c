//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 100

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

void insert(Node* node, char data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

int main() {
    Node* root = NULL;

    insert(root, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');

    inorder(root);
    printf("\n");
    preorder(root);

    return 0;
}