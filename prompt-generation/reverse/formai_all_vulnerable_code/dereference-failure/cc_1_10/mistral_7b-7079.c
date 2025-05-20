//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: excited
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

Node* newNode(int key, char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int key, char* name) {
    if (root == NULL)
        return newNode(key, name);

    if (key < root->key)
        root->left = insertNode(root->left, key, name);
    else if (key > root->key)
        root->right = insertNode(root->right, key, name);

    return root;
}

void printNode(Node* node) {
    if (node == NULL)
        return;

    printf("Key: %d, Name: %s\n", node->key, node->name);
    printNode(node->left);
    printNode(node->right);
}

int main() {
    srand(time(NULL));
    int keys[] = { 10, 20, 30, 40, 50, 60, 70 };
    char names[7][20] = { "John Doe", "Jane Smith", "Mike Johnson", "Sarah Brown", "Tom Williams", "Lucy Davis", "Mark Green" };

    Node* root = NULL;

    for (int i = 0; i < 7; i++) {
        root = insertNode(root, keys[i], names[i]);
        printf("Inserted: Key: %d, Name: %s\n", keys[i], names[i]);
    }

    printf("\nBinary Search Tree:\n");
    printNode(root);

    return 0;
}