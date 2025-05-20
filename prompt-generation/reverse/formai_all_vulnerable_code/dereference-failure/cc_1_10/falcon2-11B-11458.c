//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Node struct
struct Node {
    int key;
    struct Node *left, *right;
};

// Binary Search Tree
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal function
void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
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
    root = insert(root, 90);
    root = insert(root, 100);
    root = insert(root, 110);

    printf("\nInorder traversal of BST is: ");
    inorder(root);

    return 0;
}