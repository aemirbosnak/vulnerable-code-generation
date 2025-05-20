//FormAI DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return getNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

int main() {
    printf("Welcome to the surreal world of Binary Search Trees!\n");
    struct Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    
    printf("Let's search for some nodes:\n");
    
    struct Node* search1 = search(root, 15);
    if (search1 != NULL) {
        printf("Found node with value %d\n", search1->data);
    }
    else {
        printf("Node not found\n");
    }
    
    struct Node* search2 = search(root, 3);
    if (search2 != NULL) {
        printf("Found node with value %d\n", search2->data);
    }
    else {
        printf("Node not found\n");
    }
    
    return 0;
}