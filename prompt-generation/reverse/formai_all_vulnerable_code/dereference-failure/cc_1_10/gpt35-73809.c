//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree(node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    printTree(root->right, space);
    printf("\n");

    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
    node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);

    printTree(root, 0);

    return 0;
}