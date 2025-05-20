//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void initNode(Node** node) {
    *node = (Node*)malloc(sizeof(Node));
    (*node)->left = NULL;
    (*node)->right = NULL;
}

Node* createNode(int data) {
    Node* newNode;
    initNode(&newNode);
    newNode->data = data;
    return newNode;
}

void insertNode(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insertNode(&((*root)->left), data);
    } else {
        insertNode(&((*root)->right), data);
    }
}

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 1; i < level; i++) {
        printf("  ");
    }

    printf("%d%c", root->data, (root->left == NULL && root->right == NULL) ? '\n' : ' ');

    if (root->left != NULL) {
        printTree(root->left, level + 1);
    }

    if (root->right != NULL) {
        printTree(root->right, level + 1);
    }
}

void printSpaces(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}

void printPyramid(int height) {
    for (int i = 0; i < height; i++) {
        int spaces = height - i - 1;

        printSpaces(spaces);

        for (int j = 0; j < i * 2 + 1; j++) {
            printf("%s", i == 0 ? " *" : j % 2 == 0 ? "  *" : "*  ");
        }

        printf("\n");
    }
}

int main() {
    Node* root = NULL;

    int numbers[] = {50, 30, 20, 45, 70, 60, 80};

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        insertNode(&root, numbers[i]);
    }

    printPyramid(log2(sizeof(numbers) / sizeof(int)) + 1);
    printTree(root, 0);

    return 0;
}