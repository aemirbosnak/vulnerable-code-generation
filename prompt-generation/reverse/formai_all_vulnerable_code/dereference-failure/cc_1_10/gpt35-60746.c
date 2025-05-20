//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

typedef struct Node *Tree;

// Function to create a new BST node
Tree createNode(int value) {
    Tree newNode = (Tree)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Tree insert(Tree root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to print the tree in InOrder Traversal
void printInOrder(Tree root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

int main() {
    Tree root = NULL;
    int values[] = {10, 8, 20, 13, 25, 18, 6};

    // Insert nodes in BST
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }
    printf("InOrder traversal of the tree: ");
    printInOrder(root);
    return 0;
}