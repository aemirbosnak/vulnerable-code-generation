//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    char name[20];
    int age;
    struct Node *left, *right;
} Node;

Node* createNode(char *name, int age) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, Node *newNode) {
    if (root == NULL)
        return newNode;

    if (strcmp(newNode->name, root->name) < 0) {
        root->left = insertNode(root->left, newNode);
    } else if (strcmp(newNode->name, root->name) > 0) {
        root->right = insertNode(root->right, newNode);
    }

    return root;
}

void inOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%s: %d\n", root->name, root->age);
    inOrderTraversal(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;

    root = insertNode(root, createNode("John Doe", 30));
    root = insertNode(root, createNode("Jane Doe", 25));
    root = insertNode(root, createNode("Bob Smith", 45));
    root = insertNode(root, createNode("Alice Johnson", 28));

    inOrderTraversal(root);

    freeTree(root);

    return 0;
}