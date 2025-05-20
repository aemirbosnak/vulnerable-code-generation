//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insertNode(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data <= (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes into the binary search tree
    insertNode(&root, 5);
    insertNode(&root, 10);
    insertNode(&root, 15);
    insertNode(&root, 20);
    insertNode(&root, 25);

    // Search for a node in the binary search tree
    struct Node* node = searchNode(root, 15);

    // Print the data of the searched node
    if (node != NULL) {
        printf("The data of the searched node is: %d\n", node->data);
    } else {
        printf("The searched node is not found in the binary search tree\n");
    }

    return 0;
}