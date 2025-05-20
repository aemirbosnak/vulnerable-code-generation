//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[20];
    int age;
    struct Node *left, *right;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* name, int age) {
    if (root == NULL) {
        return createNode(name, age);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, age);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, age);
    }

    return root;
}

void inOrderTraversal(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left, level + 1);
    printf("%*s%s: %d\n", level * 4, "", root->name, root->age);
    inOrderTraversal(root->right, level + 1);
}

int main() {
    Node* root = NULL;

    root = insert(root, "Alice", 25);
    root = insert(root, "Bob", 30);
    root = insert(root, "Charlie", 20);
    root = insert(root, "David", 28);

    inOrderTraversal(root, 0);

    free(root);

    return 0;
}