//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a node in the BST */
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

/* Define a function to create a new node with the given key */
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Define a function to insert a new node with the given key into the BST */
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        node = newNode(key);
        return node;
    }
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

/* Define a function to search for a given key in the BST */
struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->key == key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    return search(node->right, key);
}

/* Define a function to print the BST inorder */
void inorder(struct Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    return 0;
}