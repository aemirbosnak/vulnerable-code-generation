//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node {
    char data[20];
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node* node, char data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        strcpy(node->data, data);
    } else if (data < node->data) {
        insertNode(node->left, data);
    } else {
        insertNode(node->right, data);
    }
}

void searchNode(Node* node, char data) {
    if (node) {
        if (strcmp(node->data, data) == 0) {
            printf("Node found: %s\n", node->data);
        } else if (data < node->data) {
            searchNode(node->left, data);
        } else {
            searchNode(node->right, data);
        }
    } else {
        printf("Node not found\n");
    }
}

int main() {
    Node* root = NULL;
    insertNode(root, 'a');
    insertNode(root, 'c');
    insertNode(root, 'e');
    insertNode(root, 'g');
    insertNode(root, 'i');

    searchNode(root, 'c');
    searchNode(root, 'f');

    return 0;
}