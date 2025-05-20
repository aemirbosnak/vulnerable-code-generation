//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: funny
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
    strcpy(newNode->name, name);
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key, char* name) {
    if (root == NULL) {
        root = createNode(key, name);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key, name);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, name);
    } else {
        printf("Key %d already exists in the tree!\n", key);
        printf("Name %s also exists, but with a different key!\n", name);
        printf("I hope this doesn't confuse you too much, because\n");
        printf("I'm just a silly binary search tree!\n");
    }
    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("Key %d, Name %s\n", root->key, root->name);
    printInOrder(root->right);
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    int keys[10] = { 5, 3, 7, 2, 8, 1, 6, 4, 9, 0 };
    char names[10][20] = { "Bob", "Alice", "Charlie", "Eve", "Frank", "Grace", "Hank", "Ivy", "Jack", "Kate" };

    printf("Let's create a silly binary search tree!\n");

    for (int i = 0; i < 10; i++) {
        root = insertNode(root, keys[i], names[i]);
    }

    printf("In no particular order, here are some keys and their corresponding names:\n");

    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        printf("Key %d, Name %s\n", keys[j], names[j]);
    }

    printf("\nNow let's print out the keys and names in the tree in order:\n");

    printInOrder(root);

    return 0;
}