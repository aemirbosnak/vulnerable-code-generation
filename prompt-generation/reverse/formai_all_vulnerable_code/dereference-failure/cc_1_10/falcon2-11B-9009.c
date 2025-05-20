//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>

// Node structure for binary search tree
struct node {
    int key;
    struct node *left, *right;
};

// Function to insert a new node with the given key
struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Function to search for a node with the given key
struct node* search(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key)
        return search(root->left, key);
    else if (key > root->key)
        return search(root->right, key);
    else
        return root;
}

// Function to print the elements of the binary search tree inorder
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // Insert some elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);

    // Print the elements in order
    inorder(root);

    return 0;
}