//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node* node, int data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void search(Node* node, int data) {
    if (node != NULL) {
        if (node->data == data) {
            printf("Data found!\n");
        } else if (data < node->data) {
            search(node->left, data);
        } else {
            search(node->right, data);
        }
    } else {
        printf("Data not found.\n");
    }
}

int main() {
    Node* root = NULL;
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    search(root, 20);
    search(root, 10);
    search(root, 30);
    search(root, 40);
    search(root, 50);

    return 0;
}