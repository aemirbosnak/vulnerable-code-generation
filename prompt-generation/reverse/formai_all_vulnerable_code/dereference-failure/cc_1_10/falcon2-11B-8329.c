//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to insert a new node with the given key into the binary search tree
void insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return;
    }

    if (key < root->key) {
        if (root->left == NULL) {
            root->left = (struct Node*)malloc(sizeof(struct Node));
            root->left->key = key;
            root->left->left = NULL;
            root->left->right = NULL;
        } else {
            insert(root->left, key);
        }
    } else if (key > root->key) {
        if (root->right == NULL) {
            root->right = (struct Node*)malloc(sizeof(struct Node));
            root->right->key = key;
            root->right->left = NULL;
            root->right->right = NULL;
        } else {
            insert(root->right, key);
        }
    }
}

// Function to search for a given key in the binary search tree
int search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return 1;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the binary search tree in inorder traversal
void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    printf("\n");

    search(root, 20);
    search(root, 80);

    return 0;
}