//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
} Node;

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if(root == NULL) {
        root = createNewNode(value);
    } else if(value < root->data) {
        root->leftChild = insertNode(root->leftChild, value);
    } else {
        root->rightChild = insertNode(root->rightChild, value);
    }
    return root;
}

Node* searchNode(Node* root, int value) {
    if(root == NULL) {
        return NULL;
    } else if(root->data == value) {
        return root;
    } else if(value < root->data) {
        return searchNode(root->leftChild, value);
    } else {
        return searchNode(root->rightChild, value);
    }
}

void printInOrder(Node* root) {
    if(root != NULL) {
        printInOrder(root->leftChild);
        printf("%d ", root->data);
        printInOrder(root->rightChild);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    printf("In Order Traversal: ");
    printInOrder(root);
    Node* found = searchNode(root, 6);
    if(found != NULL) {
        printf("\nFound %d!", found->data);
    } else {
        printf("\nNot found!");
    }
    return 0;
}