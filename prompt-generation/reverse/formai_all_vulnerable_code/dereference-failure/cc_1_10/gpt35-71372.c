//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct node { 
    int value; 
    struct node *left; 
    struct node *right; 
}; 

struct node* createNode(int value) { 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->value = value; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    return(new_node); 
} 

struct node* insertNode(struct node* node, int value) { 
    if (node == NULL) 
        return(createNode(value)); 
  
    if (value < node->value) 
        node->left = insertNode(node->left, value); 
    else if (value > node->value) 
        node->right = insertNode(node->right, value); 
  
    return(node); 
} 

void printInorder(struct node* node) { 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
  
    printf("%d ", node->value); 
  
    printInorder(node->right); 
} 

int main() { 
    struct node *root = NULL; 
    root = insertNode(root, 6); 
    insertNode(root, 1); 
    insertNode(root, 2); 
    insertNode(root, 7); 
    insertNode(root, 4); 
  
    printf("Inorder traversal of the constructed binary search tree is: \n"); 
    printInorder(root); 
  
    return 0; 
}