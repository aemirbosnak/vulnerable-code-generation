//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char data[50];
    struct Node *left, *right;
} Node;

Node* createNode(int key, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int key, char *data) {
    if (root == NULL) {
        root = createNode(key, data);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key, data);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, data);
    }
    return root;
}

int binarySearch(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root != NULL;
    }
    if (key < root->key) {
        return binarySearch(root->left, key);
    }
    return binarySearch(root->right, key);
}

int recursiveSearch(Node *root, char *target) {
    if (root == NULL) {
        return 0;
    }
    int res = strcmp(target, root->data);
    if (res < 0) {
        return recursiveSearch(root->left, target);
    } else if (res > 0) {
        return recursiveSearch(root->right, target);
    } else {
        return 1;
    }
}

int searchTree(Node *root, int key, char *target) {
    if (root == NULL) {
        return 0;
    }
    if (binarySearch(root, key)) {
        return recursiveSearch(root, target);
    }
    return searchTree(root->left, key, target) || searchTree(root->right, key, target);
}

int main() {
    Node *root = NULL;
    int keys[] = {5, 3, 7, 1, 8, 9, 6, 4};
    char data[][50] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew"};
    int i;
    for (i = 0; i < 8; i++) {
        root = insertNode(root, keys[i], data[i]);
    }
    int targetKey = 7;
    char target[] = "grape";
    int result = searchTree(root, targetKey, target);
    if (result) {
        printf("Found %s with key %d\n", target, targetKey);
    } else {
        printf("Not found\n");
    }
    return 0;
}