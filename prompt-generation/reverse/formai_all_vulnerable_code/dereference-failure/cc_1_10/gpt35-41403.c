//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** tree, int value) {
    if (*tree == NULL) {
        *tree = createNode(value);
    } else if ((*tree)->data > value) {
        insertNode(&(*tree)->left, value);
    } else {
        insertNode(&(*tree)->right, value);
    }
}

void inorderTraversal(Node* tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

Node* searchNode(Node* tree, int value) {
    if (tree == NULL) {
        return NULL;
    } else if (tree->data == value) {
        return tree;
    } else if (tree->data > value) {
        return searchNode(tree->left, value);
    } else {
        return searchNode(tree->right, value);
    }
}

int main() {
    Node* root = NULL;

    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchValue = 40;
    Node* result = searchNode(root, searchValue);
    if (result != NULL) {
        printf("Node with value %d found!\n", searchValue);
    } else {
        printf("Node with value %d not found!\n", searchValue);
    }

    return 0;
}