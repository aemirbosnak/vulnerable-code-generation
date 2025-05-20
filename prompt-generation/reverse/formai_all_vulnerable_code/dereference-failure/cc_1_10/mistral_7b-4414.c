//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int key;
    char name[20];
    struct Node *left, *right;
} Node;

Node* createNode(int key, char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int key, char *name) {
    if (root == NULL)
        return createNode(key, name);

    if (key < root->key)
        root->left = insertNode(root->left, key, name);
    else if (key > root->key)
        root->right = insertNode(root->right, key, name);

    return root;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("(%d, %s) ", root->key, root->name);
        inorderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    int i;
    Node *root = NULL;

    for (i = 0; i < 10; i++) {
        int key = rand() % 50 + 1;
        char name[20];
        sprintf(name, "Person%d", i);
        root = insertNode(root, key, name);
    }

    printf("Binary Search Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}