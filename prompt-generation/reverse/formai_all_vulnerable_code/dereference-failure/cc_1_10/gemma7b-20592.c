//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int data;
} Node;

struct Node* insertTree(struct Node* node, int data) {
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
        node->left = NULL;
        node->right = NULL;
        node->data = data;
    } else if (data < node->data) {
        node->left = insertTree(node->left, data);
    } else {
        node->right = insertTree(node->right, data);
    }
    return node;
}

int compress(struct Node* node) {
    int count = 0;
    struct Node* current = node;
    while (current) {
        if (current->left == NULL && current->right == NULL) {
            count++;
        }
        current = current->left;
    }
    return count;
}

int main() {
    struct Node* root = NULL;
    insertTree(root, 10);
    insertTree(root, 20);
    insertTree(root, 30);
    insertTree(root, 40);
    insertTree(root, 50);
    insertTree(root, 60);
    insertTree(root, 70);
    insertTree(root, 80);
    insertTree(root, 90);
    insertTree(root, 100);

    int numCompressedNodes = compress(root);
    printf("Number of compressed nodes: %d\n", numCompressedNodes);

    return 0;
}