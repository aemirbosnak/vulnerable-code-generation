//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void traverse(Node *root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%d ", root->value);
    traverse(root->right);
}

int search(Node *root, int value) {
    if (root == NULL) {
        return 0;
    } else if (root->value == value) {
        return 1;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 9);
    insert(root, 4);
    printf("Traversal of tree: ");
    traverse(root);
    printf("\n");

    int valueToSearch = 4;
    if (search(root, valueToSearch)) {
        printf("%d is found in tree.\n", valueToSearch);
    } else {
        printf("%d is not found in tree.\n", valueToSearch);    
    }

    return 0;
}