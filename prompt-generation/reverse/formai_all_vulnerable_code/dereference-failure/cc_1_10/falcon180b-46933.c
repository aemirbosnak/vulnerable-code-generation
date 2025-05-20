//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Create a new node with the given data value
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data value into the binary search tree
void insertNode(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data);
    } else if (data > root->data) {
        insertNode(root->right, data);
    }
}

// Perform an inorder traversal of the binary search tree and print the data values
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Create a new binary search tree
    node* root = NULL;

    // Insert some data values into the tree
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 12);

    // Print the data values in the tree using an inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}