//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
        return root;
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inOrder(struct node* root) {
    if (root!= NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inOrder(root);
    return 0;
}