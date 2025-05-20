//FormAI DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode * leftChild;
    struct BinaryTreeNode * rightChild;
};

typedef struct BinaryTreeNode Node;


/* Function to insert a new node */
Node * insertNode(Node * node, int value) {
    /* If node is empty, create a new node */
    if (node == NULL) {
        Node * newnode = (Node*)malloc(sizeof(Node));
        newnode->data = value;
        newnode->leftChild = NULL;
        newnode->rightChild = NULL;
        return newnode;
    }
    /* Traverse the tree to find a position to insert the new node */
    if (value < node->data) {
        node->leftChild = insertNode(node->leftChild, value);
    }
    else {
        node->rightChild = insertNode(node->rightChild, value);
    }
    return node;
}


/* Function to search for a node */
Node * search(Node * node, int value) {
    /* If tree is empty or node is present at root */
    if (node == NULL || node->data == value) {
        return node;
    }
    /* If key is greater than root's key */
    if (node->data < value) {
        return search(node->rightChild, value);
    }
    /* If key is smaller than root's key */
    return search(node->leftChild, value);
}


/* Function to traverse the tree in-order */
void inOrderTraversal(Node * node) {
    if (node != NULL) {
        inOrderTraversal(node->leftChild);
        printf("%d ", node->data);
        inOrderTraversal(node->rightChild);
    }
}


int main() {
    Node * root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("In-order traversal of the binary search tree:\n");
    inOrderTraversal(root);
    printf("\n");
    int value = 60;
    Node * searchNode = search(root, value);
    if (searchNode == NULL) {
        printf("%d not found in the binary search tree.\n", value);
    }
    else {
        printf("%d found in the binary search tree.\n", searchNode->data);
    }
    return 0;
}