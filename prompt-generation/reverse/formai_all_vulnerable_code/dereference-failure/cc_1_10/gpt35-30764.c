//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int searchNode(Node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    }
    return 0;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 8);
    insertNode(root, 3);
    insertNode(root, 10);
    insertNode(root, 1);
    insertNode(root, 6);
    insertNode(root, 14);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 13);

    printf("InOrder Traversal: ");
    printInOrder(root);
    printf("\n");

    int search1 = 4;
    int search2 = 11;

    if (searchNode(root, search1)) {
        printf("%d is present in the tree.\n", search1);
    } else {
        printf("%d is not present in the tree.\n", search1);
    }

    if (searchNode(root, search2)) {
        printf("%d is present in the tree.\n", search2);
    } else {
        printf("%d is not present in the tree.\n", search2);
    }

    return 0;
}