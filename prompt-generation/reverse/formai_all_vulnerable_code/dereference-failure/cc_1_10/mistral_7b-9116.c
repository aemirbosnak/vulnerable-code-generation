//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    char key[32];
    int height;
    struct Node *left, *right;
} Node;

Node *newNode(char *str) {
    Node *new = (Node *)malloc(sizeof(Node));
    strcpy(new->key, str);
    new->height = 0;
    new->left = new->right = NULL;
    return new;
}

int height(Node *N) {
    if (N == NULL) return -1;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int balanceFactor(Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

Node *rotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *rebalance(Node *N) {
    int bf = balanceFactor(N);

    if (bf > 1) {
        N->height = 1 + max(height(N->left), height(N->right));
        if (balanceFactor(N->left) < 0)
            N->left = rotateRight(N->left);
        N = rotateLeft(N);
    }

    return N;
}

Node *insert(Node *root, char *str) {
    if (root == NULL) {
        root = newNode(str);
    } else if (strcmp(root->key, str) > 0) {
        root->left = insert(root->left, str);
    } else {
        root->right = insert(root->right, str);
    }

    root = rebalance(root);
    return root;
}

void printTree(Node *root, int space) {
    if (root == NULL) return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) printf(" ");
    printf("%s\n", root->key);

    printTree(root->left, space);
}

int main() {
    Node *root = NULL;
    char str[32];

    while (true) {
        printf("Enter a word to insert (or type 'quit' to exit): ");
        scanf("%s", str);

        if (strcmp(str, "quit") == 0) break;

        root = insert(root, str);
    }

    printTree(root, 0);

    return 0;
}