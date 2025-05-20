//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct node* node) {
    if (node == NULL) return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return (lheight > rheight)? lheight + 1 : rheight + 1;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
        return root;
    }
    else if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

void inorder(struct node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    return 0;
}