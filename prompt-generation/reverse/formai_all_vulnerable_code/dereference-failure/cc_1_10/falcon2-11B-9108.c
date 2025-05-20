//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int value;
    struct node* left;
    struct node* right;
} node;

node* createNode(int key, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int key, int value) {
    if (root == NULL) {
        return createNode(key, value);
    } else if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    } else {
        root->value = value;
    }
    return root;
}

void inorder(node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d,%d\n", root->key, root->value);
        inorder(root->right);
    }
}

int main() {
    node* root = NULL;
    int nums[5] = {4, 2, 6, 1, 3};
    int values[5] = {10, 8, 9, 7, 5};

    for (int i = 0; i < 5; i++) {
        root = insert(root, nums[i], values[i]);
    }

    inorder(root);

    return 0;
}