//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // Define node structure
    int value;
    struct node *leftChild;
    struct node *rightChild;
} Node;

// Function to create new Node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Function to insert Node in binary tree
Node* insertNode(Node* root, int value) {
    if(root == NULL) {
        root = createNode(value);
        return root;
    }
    else if(value < root->value) {
        root->leftChild = insertNode(root->leftChild, value);
    }
    else {
        root->rightChild = insertNode(root->rightChild, value);
    }
    return root;
}

// Function to recursively print Nodes in binary tree
void printNodes(Node* root, int space) {
    if(root == NULL) {
        return;
    }
    space += 10; // Increase the indentation for this level
    printNodes(root->rightChild, space); // Print right child first
    printf("\n");
    for(int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value); // Print the value of the Node
    printNodes(root->leftChild, space); // Print left child last
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 20);
    insertNode(root, 70);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 25);
    insertNode(root, 35);
    printf("\nRecursive Binary Tree Visualization: \n");
    printNodes(root, 0); // Start printing from the root with 0 indentation
    return 0;
}