//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertNode(struct Node** root, int data) {
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
struct Node* searchNode(struct Node* root, int data) {
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

// Function to traverse the binary search tree
void traverse(struct Node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 6);
    insertNode(&root, 4);

    // Search for 5
    struct Node* five = searchNode(root, 5);
    if (five != NULL) {
        printf("5 found at %p\n", five);
    } else {
        printf("5 not found\n");
    }

    // Search for 2
    struct Node* two = searchNode(root, 2);
    if (two != NULL) {
        printf("2 found at %p\n", two);
    } else {
        printf("2 not found\n");
    }

    traverse(root);

    return 0;
}