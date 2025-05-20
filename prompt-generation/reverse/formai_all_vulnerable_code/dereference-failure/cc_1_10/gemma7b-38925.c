//Gemma-7B DATASET v1.0 Category: Data mining ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_HEIGHT 20

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node* node, char data) {
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insertNode(node->left, data);
    } else {
        insertNode(node->right, data);
    }
}

int searchNode(Node* node, char data) {
    if (node == NULL) {
        return 0;
    } else if (node->data == data) {
        return 1;
    } else if (data < node->data) {
        return searchNode(node->left, data);
    } else {
        return searchNode(node->right, data);
    }
}

int main() {
    Node* root = NULL;
    insertNode(root, 'a');
    insertNode(root, 'c');
    insertNode(root, 'e');
    insertNode(root, 'g');
    insertNode(root, 'i');
    insertNode(root, 'k');

    if (searchNode(root, 'c') == 1) {
        printf("Node found.\n");
    } else {
        printf("Node not found.\n");
    }

    return 0;
}