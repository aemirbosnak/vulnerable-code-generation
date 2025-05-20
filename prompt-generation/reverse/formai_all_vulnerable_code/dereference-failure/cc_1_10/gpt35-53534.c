//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define BST Node struct
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new BST Node
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a Node into the BST
void insert(Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

// Function to print the BST in order traversal
void printInOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to visualize the BST
void visualize(Node *root, int level) {
    if (root == NULL) {
        return;
    }
    visualize(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d\n", root->data);
    visualize(root->left, level + 1);
}

int main() {
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 11);
    insert(&root, 15);

    printf("In Order Traversal:\n");
    printInOrder(root);

    printf("\n\nVisualization:\n");
    visualize(root, 0);

    return 0;
}