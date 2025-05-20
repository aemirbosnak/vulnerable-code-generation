//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_KEY 100

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void insertNode(Node** root, int key) {
    Node* current = *root;

    if (!current) {
        *root = createNode(key);
        return;
    }

    if (key < current->key) {
        if (!current->left) {
            current->left = createNode(key);
        } else {
            insertNode(current->left, key);
        }
    } else {
        if (!current->right) {
            current->right = createNode(key);
        } else {
            insertNode(current->right, key);
        }
    }
}

int searchNode(Node* root, int key) {
    if (!root) {
        return -1;
    }

    if (root->key == key) {
        return 0;
    }

    if (key < root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

int main() {
    Node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 20);
    insertNode(&root, 35);
    insertNode(&root, 10);
    insertNode(&root, 45);
    insertNode(&root, 60);

    printf("The value %d is located at node %d\n", 35, searchNode(root, 35));

    return 0;
}