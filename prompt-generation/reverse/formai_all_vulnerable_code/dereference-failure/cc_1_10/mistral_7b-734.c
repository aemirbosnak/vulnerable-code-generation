//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NODES 100000
typedef struct Node {
    int key;
    char name[20];
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int key, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int key, char* name) {
    if (root == NULL) {
        return createNode(key, name);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key, name);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, name);
    } else {
        strcpy(root->name, name);
    }
    return root;
}
void inOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d %s\n", node->key, node->name);
    inOrderTraversal(node->right);
}
int main() {
    srand(time(NULL));
    Node* root = NULL;
    int keys[MAX_NODES];
    char names[MAX_NODES][20];
    for (int i = 0; i < MAX_NODES; i++) {
        keys[i] = rand() % 100;
        sprintf(names[i], "Person %d", i);
        root = insertNode(root, keys[i], names[i]);
    }
    printf("Mind-bending Binary Search Tree:\n");
    inOrderTraversal(root);
    return 0;
}