//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(const char* name, int age) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, const char* name, int age) {
    if (root == NULL) {
        root = newNode(name, age);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, age);
    } else {
        root->right = insert(root->right, name, age);
    }
    return root;
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; ++i) {
        printf("  ");
    }

    printf("-%s-\n", node->name);

    if (node->left != NULL) {
        printTree(node->left, level + 1);
    }

    if (node->right != NULL) {
        printTree(node->right, level + 1);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, "Alice", 25);
    root = insert(root, "Bob", 30);
    root = insert(root, "Charlie", 20);
    root = insert(root, "David", 35);
    root = insert(root, "Eve", 22);
    root = insert(root, "Frank", 40);
    root = insert(root, "Grace", 32);

    printTree(root, 0);

    return 0;
}