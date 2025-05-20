//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printTree(struct Node* node, int space) {
    if (node == NULL) {
        return;
    }

    space += 10;

    printTree(node->right, space);

    printf("\n");

    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", node->value);

    printTree(node->left, space);
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    printTree(root, 0);

    return 0;
}