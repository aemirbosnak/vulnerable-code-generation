//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

void inorderTraversal(node* root) {
    if (root!= NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    printf("Inorder traversal of the BST is:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}