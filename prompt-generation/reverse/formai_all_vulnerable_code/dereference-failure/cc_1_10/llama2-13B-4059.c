//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newNode(int data) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertNode(struct BSTNode** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else {
        if (data < (*root)->data) {
            insertNode(&(*root)->left, data);
        } else {
            insertNode(&(*root)->right, data);
        }
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* searchNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    } else {
        return root;
    }
}

// Function to delete a node from the binary search tree
void deleteNode(struct BSTNode** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        deleteNode(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else {
            struct BSTNode* temp = (*root)->left == NULL ? (*root)->right : (*root)->left;
            deleteNode(&temp, (*root)->data);
            free(*root);
            *root = temp;
        }
    }
}

int main() {
    struct BSTNode* root = NULL;
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);

    struct BSTNode* node = searchNode(root, 4);
    if (node != NULL) {
        printf("Found node with value %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    deleteNode(&root, 4);

    node = searchNode(root, 4);
    if (node != NULL) {
        printf("Found node with value %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}