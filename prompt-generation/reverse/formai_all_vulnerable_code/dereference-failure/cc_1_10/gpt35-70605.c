//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
// Decentralized Binary Search Tree Program

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void traverse(node* root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%d ", root->data);
    traverse(root->right);
}

int main() {
    node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    printf("Binary Search Tree Traversal: ");
    traverse(root);
    return 0;
}