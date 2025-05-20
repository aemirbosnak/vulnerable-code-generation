//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[21];
    int height;
    struct Node *left, *right;
} Node;

Node *newNode(const char *key) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->key, key);
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

int height(Node *node) {
    if (node == NULL)
        return -1;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void fixHeight(Node *node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node *rotateRight(Node *p) {
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

Node *insert(Node *node, const char *key) {
    if (node == NULL)
        return newNode(key);

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);

    fixHeight(node);
    return node;
}

void printTree(Node *node, int space) {
    if (node == NULL)
        return;

    space += 10;

    printTree(node->right, space);

    printf("\n%*s%s", space, "", node->key);

    printTree(node->left, space);
}

int main() {
    Node *root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "grape");
    root = insert(root, "orange");
    root = insert(root, "kiwi");
    root = insert(root, "mango");
    root = insert(root, "pineapple");

    printTree(root, 0);

    return 0;
}