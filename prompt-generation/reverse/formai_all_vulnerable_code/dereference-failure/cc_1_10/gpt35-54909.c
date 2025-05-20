//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

struct TreeNode* createNode(int data) { //creating a new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* node, int data) { //inserting a new node
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->leftChild = insert(node->leftChild, data);
    }
    else if (data > node->data) {
        node->rightChild = insert(node->rightChild, data);
    }
    return node;
}

struct TreeNode* search(struct TreeNode* node, int key) { //searching for a node
    if (node == NULL || node->data == key) {
        return node;
    }
    if (node->data < key) {
        return search(node->rightChild, key);
    }
    return search(node->leftChild, key);
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Binary Search Tree created successfully!\n");

    int key = 60;
    struct TreeNode* searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Node with key %d found in the BST\n", key);
    }
    else {
        printf("Node with key %d does not exist in the BST\n", key);
    }
    return 0;
}