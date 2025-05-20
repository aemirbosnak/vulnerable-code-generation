//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20 //Maximum size of the binary tree

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//Function to create a new TreeNode
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a TreeNode in the binary tree
void insert(TreeNode* root, int data) {
    if(root == NULL) {
        root = createTreeNode(data);
        return;
    }
    
    if(data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

//Function to print the binary tree in inorder traversal
void printInorder(TreeNode* root) {
    if(root == NULL)
        return;
    
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    srand(time(NULL)); //Seed the random number generator
    
    TreeNode* root = createTreeNode(rand() % MAX_SIZE); //Create the root TreeNode with random data
    
    //Insert 10 more TreeNodes with random data
    for(int i=0; i<10; i++)
        insert(root, rand() % MAX_SIZE);
    
    //Print the binary tree in inorder traversal
    printInorder(root);
    
    return 0;
}