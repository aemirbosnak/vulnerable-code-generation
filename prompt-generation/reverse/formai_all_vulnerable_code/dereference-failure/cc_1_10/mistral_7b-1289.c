//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_HEIGHT 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int height;
    struct Node *left, *right;
} Node;

Node *createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->height = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeightRecursive(Node *node) {
    if (node == NULL)
        return 0;

    int leftHeight = getHeightRecursive(node->left);
    int rightHeight = getHeightRecursive(node->right);

    node->height = 1 + max(leftHeight, rightHeight);

    return node->height;
}

Node *insert(Node *root, Node *newNode) {
    if (root == NULL)
        return newNode;

    if (strcmp(newNode->name, root->name) < 0) {
        root->left = insert(root->left, newNode);
    } else {
        root->right = insert(root->right, newNode);
    }

    getHeightRecursive(root);
    return root;
}

void printTree(Node *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n%*s%s", space, "", root->name);

    printTree(root->left, space);
}

void destroy(Node *node) {
    if (node == NULL)
        return;

    destroy(node->left);
    destroy(node->right);

    free(node);
}

int main() {
    Node *root = NULL;

    const char *names[] = {
        "John Doe",
        "Jane Smith",
        "Michael Johnson",
        "James Brown",
        "Emma Watson",
        "Tom Cruise",
        "Angelina Jolie",
        "Brad Pitt",
        "Meryl Streep",
        "Will Smith"
    };

    int i;

    for (i = 0; i < 10; i++) {
        Node *newNode = createNode(names[i]);
        root = insert(root, newNode);
    }

    printf("Binary Search Tree:\n");
    printTree(root, 0);

    printf("\nHeight of the tree: %d\n", height(root));

    destroy(root);

    return 0;
}