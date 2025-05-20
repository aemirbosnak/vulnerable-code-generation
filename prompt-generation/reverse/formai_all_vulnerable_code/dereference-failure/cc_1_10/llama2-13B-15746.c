//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024
#define MAX_TREE_SIZE 1024

// Node structure to represent the BST
struct Node {
    int data;
    struct Node *left, *right;
    char name[20];
};

// Function to create a new node
struct Node* newNode(int data, char name[20]) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    strcpy(node->name, name);
    return node;
}

// Function to insert a node into the BST
void insertNode(struct Node** root, int data, char name[20]) {
    if (*root == NULL) {
        *root = newNode(data, name);
    } else {
        if (data < (*root)->data) {
            insertNode(&(*root)->left, data, name);
        } else {
            insertNode(&(*root)->right, data, name);
        }
    }
}

// Function to search a node in the BST
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print the BST
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%s (%d)", root->name, root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;
    insertNode(&root, 5, "Apple");
    insertNode(&root, 3, "Banana");
    insertNode(&root, 7, "Cherry");
    insertNode(&root, 2, "Orange");
    insertNode(&root, 1, "Grape");
    printTree(root);
    return 0;
}