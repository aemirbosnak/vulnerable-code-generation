//FormAI DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        // Empty tree
        return createNode(data);
    } else if(data <= root->data) {
        // Insert in left subtree
        root->left = insert(root->left, data);
    } else if(data > root->data) {
        // Insert in right subtree
        root->right = insert(root->right, data);
    }
    return root;
}

struct node *search(struct node *root, int data) {
    if(root == NULL) {
        // Data not found
        return NULL;
    } else if(data == root->data) {
        // Data found
        return root;
    } else if(data < root->data) {
        // Search in left subtree
        return search(root->left, data);
    } else if(data > root->data) {
        // Search in right subtree
        return search(root->right, data);
    }
}

void inorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 60);
    insert(root, 10);
    insert(root, 30);
    insert(root, 55);
    insert(root, 80);
    printf("Inorder traversal of binary search tree : ");
    inorder(root);
    int searchData = 30;
    struct node *result = search(root, searchData);
    if(result == NULL) {
        printf("%d not found in the tree.", searchData);
    } else {
        printf("%d found in the tree.", result->data);
    }
    return 0;
}