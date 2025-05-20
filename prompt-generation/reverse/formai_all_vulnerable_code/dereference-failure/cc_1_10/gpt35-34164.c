//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *leftChild;
    struct BSTNode *rightChild;
} BSTNode;

BSTNode* createNode(int value) {
    BSTNode* newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->data) {
        node->leftChild = insert(node->leftChild, value);
    }
    else if (value > node->data) {
        node->rightChild = insert(node->rightChild, value);
    }
    return node;
}

void inorderTraversal(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->leftChild);
    printf("%d ", node->data);
    inorderTraversal(node->rightChild);
}

void preorderTraversal(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorderTraversal(node->leftChild);
    preorderTraversal(node->rightChild);
}

void postorderTraversal(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->leftChild);
    postorderTraversal(node->rightChild);
    printf("%d ", node->data);
}

BSTNode* search(BSTNode* node, int value) {
    if (node == NULL || node->data == value) {
        return node;
    }
    if (node->data > value) {
        return search(node->leftChild, value);
    }
    return search(node->rightChild, value);
}

int main() {
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 25);
    insert(root, 75);
    insert(root, 15);
    insert(root, 30);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    BSTNode* found = search(root, 25);
    if (found != NULL) {
        printf("Found %d\n", found->data);
    }
    else {
        printf("Not found\n");
    }

    found = search(root, 40);
    if (found != NULL) {
        printf("Found %d\n", found->data);
    }
    else {
        printf("Not found\n");
    }

    return 0;
}