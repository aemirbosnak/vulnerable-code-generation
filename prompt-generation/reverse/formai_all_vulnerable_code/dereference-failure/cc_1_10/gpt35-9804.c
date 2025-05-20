//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *createNode(int value) {
    NODE *node = (NODE*) malloc(sizeof(NODE));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NODE *insert(NODE *node, int value) {
    if(node == NULL) {
        return createNode(value);
    }
    if(value >= node->data) {
        node->right = insert(node->right, value);
    }
    else {
        node->left = insert(node->left, value);
    }
    return node;
}

NODE *search(NODE *node, int value) {
    if(node == NULL || node->data == value) {
        return node;
    }
    if(value > node->data) {
        return search(node->right, value);
    }
    else {
        return search(node->left, value);
    }
}

void inorder(NODE *node) {
    if(node != NULL) {
        inorder(node->left);
        printf("%d -> ", node->data);
        inorder(node->right);
    }
}

int main() {
    NODE *root = NULL;

    printf("Immersion Program: Binary Search Tree\n");
    printf("Insert Values: 5, 2, 7, 1, 3, 6, 8\n");

    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("In-order Traversal:\n");

    inorder(root);
    printf("\n\n");

    int value = 6;

    NODE *searchNode = search(root, value);

    if(searchNode == NULL) {
        printf("Value %d not found.", value);
    }
    else {
        printf("Value %d found!\n", searchNode->data);
    }

    return 0;
}