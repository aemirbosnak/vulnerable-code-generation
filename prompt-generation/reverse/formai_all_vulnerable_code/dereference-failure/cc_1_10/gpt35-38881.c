//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node* createNode(int value) {
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insert(node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->value)
        root->left = insert(root->left, value);
    else if(value > root->value)
        root->right = insert(root->right, value);

    return root;
}

node* search(node* root, int value) {
    if(root == NULL || root->value == value)
        return root;

    if(value < root->value)
        return search(root->left, value);

    return search(root->right, value);
}

void printTree(node* root) {
    if(root == NULL)
        return;

    printf("%d\n", root->value);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Tree contents:\n");
    printTree(root);

    int searchValue = 60;
    node* result = search(root, searchValue);

    if(result == NULL)
        printf("%d not found in tree\n", searchValue);
    else
        printf("%d found in tree\n", searchValue);

    return 0;
}