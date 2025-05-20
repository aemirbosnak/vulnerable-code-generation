//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into the tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        node = newNode(data);
        return node;
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to search for a node with given data
struct Node* search(struct Node* node, int data) {
    if (node == NULL || node->data == data)
        return node;

    if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

// Function to print the inorder traversal of the tree
void inorder(struct Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;

    // Insert data into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the inorder traversal of the tree
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}