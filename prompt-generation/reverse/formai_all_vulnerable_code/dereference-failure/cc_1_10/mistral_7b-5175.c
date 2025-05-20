//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[21];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL)
        return newNode;

    int cmp = strcmp(root->key, newNode->key);
    if (cmp < 0)
        root->right = insertNode(root->right, newNode);
    else if (cmp > 0)
        root->left = insertNode(root->left, newNode);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s ", root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, createNode("apple"));
    root = insertNode(root, createNode("banana"));
    root = insertNode(root, createNode("cherry"));
    root = insertNode(root, createNode("grape"));
    root = insertNode(root, createNode("kiwi"));
    root = insertNode(root, createNode("mango"));
    root = insertNode(root, createNode("orange"));
    root = insertNode(root, createNode("pineapple"));
    root = insertNode(root, createNode("quince"));
    root = insertNode(root, createNode("strawberry"));

    printf("In-order traversal of Binary Search Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}