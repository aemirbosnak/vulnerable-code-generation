//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// structure definition for the node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function to create new node
struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a node
struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// function to draw the tree recursively
void drawTree(struct node *root, int depth) {
    if (root == NULL) {
        return;
    }
    drawTree(root->right, depth + 1);
    for (int i = 1; i <= depth; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    drawTree(root->left, depth + 1);
}

// main function
int main() {
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    drawTree(root, 0);
    return 0;
}