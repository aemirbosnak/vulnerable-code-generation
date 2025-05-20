//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>

// A binary search tree node
struct Node {
    int key;
    struct Node* left, *right;
};

// Function to insert a new node with given key
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return (struct Node*) malloc(sizeof(struct Node));

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Function to find a node with given key in a BST
struct Node* search(struct Node* node, int key) {
    if (node == NULL)
        return NULL;

    if (key < node->key)
        return search(node->left, key);
    else if (key > node->key)
        return search(node->right, key);
    else
        return node;
}

// Function to print the nodes of a BST in inorder
void inorder(struct Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Create a BST with the following structure:
    // 12
    //  \
    //    10
    //    \
    //      14
    //     /
    //    /
    //   8
    //  /
    //  5
    root = insert(root, 12);
    insert(root, 10);
    insert(root, 14);
    insert(root, 8);
    insert(root, 5);

    // Print the nodes of the BST in inorder
    inorder(root);

    return 0;
}