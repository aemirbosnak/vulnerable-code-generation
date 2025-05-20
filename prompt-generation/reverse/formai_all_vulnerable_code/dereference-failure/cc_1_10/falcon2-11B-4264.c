//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct node *root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);
    inorder(root);
    printf("\n");
    printf("inorder traversal of the tree is ");
    inorder(root);
    return 0;
}