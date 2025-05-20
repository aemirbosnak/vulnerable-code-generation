//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Structure for binary search tree node
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
void insert(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
        return;
    }

    if (key < root->key) {
        if (root->left == NULL) {
            root->left = createNode(key);
        } else {
            insert(root->left, key);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(key);
        } else {
            insert(root->right, key);
        }
    }
}

// Function to print the binary search tree inorder
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree: \n");
    inorderTraversal(root);

    return 0;
}