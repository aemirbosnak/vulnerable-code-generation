//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void insert(Node* node, int data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return;
    }

    if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

int main() {
    Node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);

    inorder(root);
    printf("\n");
    preorder(root);

    return 0;
}