//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node** root, int val) {
    if (*root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
    } else if (val < (*root)->val) {
        insert(&((*root)->left), val);
    } else {
        insert(&((*root)->right), val);
    }
}

Node* search(Node* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    } else if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->val);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 6);
    insert(&root, 8);

    printf("In order traversal:\n");
    printInOrder(root);
    printf("\n");

    Node* foundNode = search(root, 4);
    if (foundNode != NULL) {
        printf("Found node with value 4\n");
    } else {
        printf("Node with value 4 not found\n");
    }

    foundNode = search(root, 9);
    if (foundNode != NULL) {
        printf("Found node with value 9\n");
    } else {
        printf("Node with value 9 not found\n");
    }

    return 0;
}