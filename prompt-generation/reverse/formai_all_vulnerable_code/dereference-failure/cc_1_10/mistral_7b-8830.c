//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int key;
    char name[30];
    struct Node* left;
    struct Node* right;
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
        return createNode(key, name);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key, name);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, name);
    } else {
        printf("Error: Key already exists.\n");
        free(name);
        return root;
    }

    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        return searchNode(root->left, key);
    } else if (key > root->key) {
        return searchNode(root->right, key);
    } else {
        return root;
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d %s\n", root->key, root->name);
        inorderTraversal(root->right);
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
    srand(time(NULL));
    Node* root = NULL;

    printf("Welcome to the Shocking Binary Search Tree!\n");
    printf("Get ready for some unexpected and awe-inspiring tree action!\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        int key = rand() % 100 + 1;
        char name[30];
        sprintf(name, "Name%d", i);
        root = insertNode(root, key, name);
    }

    printf("Searching for a key...\n");
    int keyToFind = rand() % 100 + 1;
    Node* foundNode = searchNode(root, keyToFind);

    if (foundNode != NULL) {
        printf("Congratulations! You found the node with key %d and name %s!\n", foundNode->key, foundNode->name);
    } else {
        printf("Oh no! The key %d was not found in the tree. Better luck next time!\n", keyToFind);
    }

    printf("Time for some tree magic!\n");
    inorderTraversal(root);

    printf("The tree has grown too big. It's time to destroy it.\n");
    destroyTree(root);

    printf("The tree is gone, but the memories of its shocking existence will remain with us forever.\n");

    return 0;
}