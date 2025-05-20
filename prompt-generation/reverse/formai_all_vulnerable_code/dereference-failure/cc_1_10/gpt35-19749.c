//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int arr[] = { 15, 10, 20, 8, 12, 16, 25 };
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Inorder Traversal of the BST:\n");
    inorderTraversal(root);

    return 0;
}