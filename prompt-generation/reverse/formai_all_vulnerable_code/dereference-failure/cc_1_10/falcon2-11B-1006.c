//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Node struct for binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
int search(Node* root, int data) {
    if (root == NULL) {
        return -1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root->data;
    }
}

// Function to print the binary search tree
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = NULL;

    // Inserting nodes
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);
    insert(&root, 80);

    // Searching for a node
    int searchData = 60;
    int result = search(root, searchData);

    printf("Result: %d\n", result);

    // Printing the binary search tree
    printf("Binary Search Tree: \n");
    printTree(root);

    return 0;
}