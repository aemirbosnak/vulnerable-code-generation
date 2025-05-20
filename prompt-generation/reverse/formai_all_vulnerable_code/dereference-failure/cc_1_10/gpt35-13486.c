//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

// Function to create a new node
struct node * createNode(int data) {
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a BST
struct node * insert(struct node * node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(data);
    }
    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // Return the (unchanged) node pointer
    return node;
}

// Function to search for a key in a BST
struct node * search(struct node * node, int key) {
    // Base Cases: root is null or key is present at root
    if (node == NULL || node->data == key) {
        return node;
    }
    // Key is greater than root's key
    if (node->data < key) {
        return search(node->right, key);
    }
    // Key is smaller than root's key
    return search(node->left, key);
}

int main() {
    struct node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Test search function
    int key = 60;
    struct node * result = search(root, key);
    if (result == NULL) {
        printf("Key %d not found in tree\n", key);
    } else {
        printf("Key %d found in tree\n", key);
    }

    key = 90;
    result = search(root, key);
    if (result == NULL) {
        printf("Key %d not found in tree\n", key);
    } else {
        printf("Key %d found in tree\n", key);
    }

    return 0;
}