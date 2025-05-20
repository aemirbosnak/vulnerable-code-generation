//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_KEY 100

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void insert(Node** root, int key) {
    Node* node = *root;

    if (!node) {
        *root = createNode(key);
        return;
    }

    if (key < node->key) {
        if (node->left == NULL) {
            node->left = createNode(key);
        } else {
            insert(node->left, key);
        }
    } else if (key > node->key) {
        if (node->right == NULL) {
            node->right = createNode(key);
        } else {
            insert(node->right, key);
        }
    }
}

int search(Node* root, int key) {
    if (!root) {
        return -1;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return 0;
    }
}

void traverse(Node* root) {
    if (root) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int main() {
    Node* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 4);

    traverse(root);

    return 0;
}