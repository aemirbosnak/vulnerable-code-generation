//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *search(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->value == value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;

    // insert sample values
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);

    // print the tree inorder
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    // search for a value
    int searchValue = 30;
    Node *searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("%d is found in the BST.\n", searchValue);
    } else {
        printf("%d is not found in the BST.\n", searchValue);
    }
    return 0;
}