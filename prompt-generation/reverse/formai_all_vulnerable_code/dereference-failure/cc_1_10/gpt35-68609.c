//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>

/* Define a struct for a tree node */
struct TreeNode {
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

/* Helper function to create a new tree node */
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

/* Helper function to insert a node into the tree */
struct TreeNode* insertNode(struct TreeNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->leftChild = insertNode(node->leftChild, data);
    } else if (data > node->data) {
        node->rightChild = insertNode(node->rightChild, data);
    }
    return node;
}

/* Helper function to print tree nodes in-order */
void printInOrder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->leftChild);
    printf("%d ", node->data);
    printInOrder(node->rightChild);
}

int main() {
    struct TreeNode* root = NULL;

    /* Insert some nodes into the tree */
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 1);
    root = insertNode(root, 3);

    /* Print the nodes in-order */
    printf("The following numbers are stored in the tree in order:\n");
    printInOrder(root);

    return 0;
}