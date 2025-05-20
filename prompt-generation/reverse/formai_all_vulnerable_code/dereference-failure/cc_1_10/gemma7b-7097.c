//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* node, int value) {
    if (node == NULL) {
        node = (struct node*)malloc(sizeof(struct node));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    } else if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

struct node* search(struct node* node, int value) {
    if (node == NULL) {
        return NULL;
    } else if (node->data == value) {
        return node;
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

void printInorder(struct node* node) {
    if (node) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);

    search(root, 5) != NULL ? printf("Value found.\n") : printf("Value not found.\n");
    printInorder(root);

    return 0;
}