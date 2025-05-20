//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// define a binary search tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// define a function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// define a function to insert a node into the binary search tree
Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// define a function to search for a node in the binary search tree
Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// define a function to print the binary search tree in order
void printInOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    // create an empty binary search tree
    Node *root = NULL;

    // insert some nodes into the binary search tree
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 9);

    // print the binary search tree in order
    printf("In Order: ");
    printInOrder(root);
    printf("\n");

    // search for a node in the binary search tree
    int searchValue = 7;
    Node *searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Node with value %d found.\n", searchValue);
    } else {
        printf("Node with value %d not found.\n", searchValue);
    }

    return 0;
}