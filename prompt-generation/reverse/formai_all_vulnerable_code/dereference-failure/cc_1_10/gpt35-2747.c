//FormAI DATASET v1.0 Category: Data structures visualization ; Style: accurate
// C program to demonstrate 
// the visualization of a Binary Tree 

#include<stdio.h> 
#include<stdlib.h> 
  
// Node structure 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// Function to create a new Node 
struct Node* createNode(int value) 
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
  
// Function to print the Binary Tree 
void printTree(struct Node* root, int space) 
{ 
    int i; 
    if (root == NULL) 
        return; 
  
    space += 10; 
  
    // Process right child first 
    printTree(root->right, space); 
  
    // Print current node after space 
    printf("\n"); 
    for (i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    printTree(root->left, space); 
} 
  
// main function 
int main() 
{ 
    // Create the binary tree structure 
    struct Node *root        = createNode(1); 
    root->left               = createNode(2); 
    root->right              = createNode(3); 
    root->left->left         = createNode(4); 
    root->left->right        = createNode(5);
    root->right->left        = createNode(6);
    root->right->right       = createNode(7);
    root->left->left->left   = createNode(8);
    root->left->left->right  = createNode(9);
    root->left->right->left  = createNode(10);
    root->left->right->right = createNode(11);
  
    // print the tree 
    printTree(root, 0); 
    return 0; 
}