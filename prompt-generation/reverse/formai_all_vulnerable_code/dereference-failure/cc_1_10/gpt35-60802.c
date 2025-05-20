//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
// C program for decentralized binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node {
     int key;
     struct node *left, *right;
};

// Function to create a new node
struct node* createNewNode(int key) {
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert elements into tree
void insert(struct node* root, int key){
    if (root == NULL)
        root = createNewNode(key);
 
    if (key < root->key)
        insert(root->left, key);
 
    else if (key > root->key)
        insert(root->right, key);
}

//Function to traverse and print the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    
    struct node* root = createNewNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
 
    return 0;
}