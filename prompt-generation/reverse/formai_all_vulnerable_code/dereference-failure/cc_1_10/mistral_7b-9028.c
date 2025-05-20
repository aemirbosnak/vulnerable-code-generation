//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[30];
    int age;
    struct Node *left, *right;
} Node;

Node *createNode(const char *name, int age) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, const char *name, int age) {
    if (root == NULL) {
        root = createNode(name, age);
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, age);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name, age);
    }

    return root;
}

void printNode(const Node *node) {
    printf("%s (%d)\n", node->name, node->age);
}

void inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printNode(root);
    inOrderTraversal(root->right);
}

int main() {
    Node *root = NULL;

    root = insertNode(root, "John Doe", 30);
    root = insertNode(root, "Jane Smith", 25);
    root = insertNode(root, "Bob Johnson", 45);
    root = insertNode(root, "Alice Williams", 35);

    printf("In Order Traversal:\n");
    inOrderTraversal(root);

    return 0;
}