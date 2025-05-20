//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, int key) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        printf("%d ", node->key);
        traverse(node->right);
    }
}

int main() {
    Node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    traverse(root);

    return 0;
}