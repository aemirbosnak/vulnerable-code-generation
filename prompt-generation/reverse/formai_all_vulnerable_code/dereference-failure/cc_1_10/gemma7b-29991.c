//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insert(struct Node* node, int data) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void search(struct Node* node, int data) {
    if (node == NULL) {
        printf("Data not found\n");
        return;
    } else if (node->data == data) {
        printf("Data found\n");
        return;
    } else if (data < node->data) {
        search(node->left, data);
    } else {
        search(node->right, data);
    }
}

int main() {
    struct Node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);

    search(root, 5);
    search(root, 12);
    search(root, 20);

    return 0;
}