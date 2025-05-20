//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int key;
    char name[20];
    struct Node *left, *right;
} Node;

Node* createNode(int key, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key, char* name) {
    if (root == NULL) {
        root = createNode(key, name);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key, name);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, name);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d %s ", root->key, root->name);
        inOrderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    int numNodes = 10;
    Node* root = NULL;

    printf("Creating Binary Search Tree with %d nodes:\n", numNodes);

    for (int i = 0; i < numNodes; i++) {
        int key = rand() % 50 + 1;
        char name[20];
        sprintf(name, "Name%d", i);
        root = insertNode(root, key, name);
    }

    printf("\nIn-Order Traversal of the created Binary Search Tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}