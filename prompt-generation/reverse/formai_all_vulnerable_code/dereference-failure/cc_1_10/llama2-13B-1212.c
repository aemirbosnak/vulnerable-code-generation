//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a tree node
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node with given data
Node *new_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert_node(Node **root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
        return;
    }

    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Function to traverse the tree in inorder
void inorder_traverse(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder_traverse(root->left);
    printf("%d ", root->data);
    inorder_traverse(root->right);
}

int main() {
    srand(time(NULL));

    Node *root = NULL;
    for (int i = 0; i < 10; i++) {
        int data = rand() % 10;
        insert_node(&root, data);
    }

    printf("Inorder traversal of the tree:\n");
    inorder_traverse(root);

    return 0;
}