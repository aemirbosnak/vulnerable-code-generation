//FormAI DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *left, *right;
} BST;

BST* create_node(int data) {
    BST *new_node = (BST *) malloc(sizeof(BST));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

BST* insert(BST *root, int data) {
    if (root == NULL)
        return create_node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void display(BST *root, int space) {
    if (root == NULL)
        return;
    space += 5;
    display(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    display(root->left, space);
}

int main() {
    BST *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    display(root, 0);
    return 0;
}