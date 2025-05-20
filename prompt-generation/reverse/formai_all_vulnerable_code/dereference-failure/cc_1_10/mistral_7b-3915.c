//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int key;
    char name[20];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->key = key;
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
        fprintf(stderr, "Key %d already exists in the tree.\n", key);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("Key: %d, Name: %s\n", root->key, root->name);
    inOrderTraversal(root->right);
}

int main(void) {
    srand(time(NULL));
    Node* root = NULL;

    printf("Creating binary search tree using surprised names and keys...\n");

    // Create 10 nodes with random keys and names
    for (int i = 0; i < 10; i++) {
        int key = rand() % 50 + 1;
        char name[20];
        sprintf(name, "Name%d", i);
        root = insertNode(root, key, name);
    }

    printf("Performing in order traversal of the binary search tree...\n");
    inOrderTraversal(root);

    printf("Searching for key 27 in the binary search tree...\n");
    Node* searchNode = root;
    while (searchNode != NULL) {
        if (searchNode->key == 27) {
            printf("Key 27 found! Name: %s\n", searchNode->name);
            break;
        } else if (searchNode->key < 27) {
            searchNode = searchNode->right;
        } else {
            searchNode = searchNode->left;
        }
    }

    printf("Deallocating memory for binary search tree nodes...\n");
    Node* currentNode = root;
    while (root != NULL) {
        root = root->left;
        free(currentNode);
        currentNode = root;
    }

    printf("Binary search tree has been successfully destroyed.\n");

    return 0;
}