//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, space + 5);

    for (int i = 0; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->value);

    printTree(root->left, space + 5);
}

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main() {
    TreeNode* root = NULL;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 2);
    root = insertNode(root, 4);

    printTree(root, 0);

    return 0;
}