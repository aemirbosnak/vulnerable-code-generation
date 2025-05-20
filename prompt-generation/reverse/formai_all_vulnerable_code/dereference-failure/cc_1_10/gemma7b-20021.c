//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 1024

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }

    return node;
}

int traverse(Node* node) {
    int count = 0;

    if (node) {
        traverse(node->left);
        traverse(node->right);
        count++;
    }

    return count;
}

int main() {
    Node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);

    int count = traverse(root);

    printf("The number of nodes in the tree is: %d", count);

    return 0;
}