//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Node {
    int key;
    char name[50];
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
    if (root == NULL)
        return createNode(key, name);

    if (key < root->key)
        root->left = insertNode(root->left, key, name);
    else if (key > root->key)
        root->right = insertNode(root->right, key, name);

    return root;
}

void printTree(Node* root, int level) {
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("%d %s\n", root->key, root->name);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

void search(Node* root, int key, char* name) {
    if (root == NULL) {
        printf("Not Found\n");
        return;
    }

    if (key < root->key) {
        printf("Searching left...\n");
        search(root->left, key, name);
    } else if (key > root->key) {
        printf("Searching right...\n");
        search(root->right, key, name);
    } else {
        printf("Found: %s %d\n", root->name, root->key);
    }
}

int main() {
    srand(time(NULL));
    int keys[10] = { 0 };
    Node* root = NULL;

    printf("Creating Binary Search Tree:\n");

    for (int i = 0; i < 10; i++) {
        int key = rand() % 100 + 1;
        keys[i] = key;

        Node* newNode = createNode(key, "");
        root = insertNode(root, key, newNode->name);

        printf("Inserted: %d\n", key);
    }

    printf("\nPrinting Tree:\n");
    printTree(root, 0);

    int searchKey;
    printf("\nEnter the key to search: ");
    scanf("%d", &searchKey);

    printf("\nSearching for %d in tree...\n", searchKey);
    search(root, searchKey, "");

    return 0;
}