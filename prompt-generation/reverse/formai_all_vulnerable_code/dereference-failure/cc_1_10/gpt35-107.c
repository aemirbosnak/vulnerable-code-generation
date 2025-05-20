//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, int key, int data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (key < node->key) {
        node->left = insert(node->left, key, data);
    } else if (key > node->key) {
        node->right = insert(node->right, key, data);
    }
    return node;
}

Node* search(Node* node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    } else if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

void print(Node* node) {
    if (node != NULL) {
        print(node->left);
        printf("%d : %d\n", node->key, node->data);
        print(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 5, 100);
    root = insert(root, 2, 200);
    root = insert(root, 8, 300);
    root = insert(root, 1, 400);
    root = insert(root, 4, 500);
    root = insert(root, 9, 600);
    root = insert(root, 3, 700);
    root = insert(root, 6, 800);
    root = insert(root, 7, 900);

    printf("Printing the tree in order:\n");
    print(root);

    printf("Searching for key 4...\n");
    Node* search_result = search(root, 4);
    if (search_result != NULL) {
        printf("Found data: %d\n", search_result->data);
    } else {
        printf("Key not found.\n");
    }

    printf("Searching for key 10...\n");
    search_result = search(root, 10);
    if (search_result != NULL) {
        printf("Found data: %d\n", search_result->data);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}