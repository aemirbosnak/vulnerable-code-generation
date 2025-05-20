//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
    } else if (strcmp(newNode->name, root->name) < 0) {
        root->left = insertNode(root->left, newNode);
    } else {
        root->right = insertNode(root->right, newNode);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s (%d)\n", root->name, root->age);
        inOrderTraversal(root->right);
    }
}

void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, createNode("John Doe", 30));
    root = insertNode(root, createNode("Jane Doe", 25));
    root = insertNode(root, createNode("Mike Doe", 35));
    root = insertNode(root, createNode("Emma Doe", 28));
    root = insertNode(root, createNode("Alice Doe", 23));

    inOrderTraversal(root);

    printf("\nDestroying the tree...\n");
    destroyTree(root);

    return 0;
}