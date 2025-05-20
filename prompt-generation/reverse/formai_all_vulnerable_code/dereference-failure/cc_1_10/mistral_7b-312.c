//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char event[100];
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char *event) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->event, event);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, char *event) {
    if (root == NULL) {
        root = createNode(event);
    } else if (strcmp(event, root->event) < 0) {
        root->left = insertNode(root->left, event);
    } else {
        root->right = insertNode(root->right, event);
    }
    return root;
}

void printTree(Node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("%s", "    ");
    }

    printf("%s\n", root->event);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main() {
    Node *root = NULL;

    root = insertNode(root, "A small bird took off from a tree.");
    root = insertNode(root, "The sun began to rise, painting the sky with hues of orange and pink.");
    root = insertNode(root, "The world was quiet, save for the gentle rustling of leaves.");
    root = insertNode(root, "Suddenly, a gentle breeze picked up, whispering through the trees.");

    printTree(root, 0);

    return 0;
}