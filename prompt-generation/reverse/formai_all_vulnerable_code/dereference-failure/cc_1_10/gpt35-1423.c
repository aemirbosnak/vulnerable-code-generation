//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* key;
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* insert(Node* root, char* key, int value) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->key = key;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (strcmp(root->key, key) > 0) {
        root->left = insert(root->left, key, value);
    } else if (strcmp(root->key, key) < 0) {
        root->right = insert(root->right, key, value);
    }
    return root;
}

int search(Node* root, char* key) {
    if (root == NULL) {
        return -1;
    }
    if (strcmp(root->key, key) == 0) {
        return root->value;
    }
    if (strcmp(root->key, key) > 0) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    char* keys[] = {"apple", "banana", "cherry", "date", "elderberry", "fig"};
    int values[] = {1, 2, 3, 4, 5, 6};
    int i, n = sizeof(keys) / sizeof(keys[0]);
    for (i = 0; i < n; i++) {
        root = insert(root, keys[i], values[i]);
    }
    printf("%d\n", search(root, "cherry"));
    printf("%d\n", search(root, "kiwi"));
    return 0;
}