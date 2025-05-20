//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// data structure for binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* newNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a new node in BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// function to traverse the tree in-order
void traverseInOrder(struct node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->data);
        traverseInOrder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    
    // inserting nodes in BST
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 30);
    insert(root, 2);
    insert(root, 18);
    insert(root, 24);
    insert(root, 8);
    
    // traversing the tree in-order
    printf("In-order traversal: ");
    traverseInOrder(root);
    printf("\n");
    
    return 0;
}