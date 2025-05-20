//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

typedef struct bstNode {
    int val; struct bstNode* left; struct bstNode* right;
} bstNode;

bstNode* newNode(int value) { // creates a new node with the given value
    bstNode* node = (bstNode*)malloc(sizeof(bstNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

bstNode* insertNode(bstNode* node, int value) { // adds new node to the BST with the given value
    if (node == NULL) return(newNode(value));    // if the tree is empty, creates a new node and returns the address
    if (value < node->val) node->left = insertNode(node->left, value);      // if the value is less than the current node, add node as left child
    else if (value > node->val) node->right = insertNode(node->right, value);// if the value is greater than the current node, add node as right child
    return(node);
}

void preOrderPrint(bstNode* node) { // prints the pre-order traversal of the BST
    if (node == NULL) return;
    printf("%d ", node->val);
    preOrderPrint(node->left);
    preOrderPrint(node->right);
}

void inOrderPrint(bstNode* node) { // prints the in-order traversal of the BST
    if (node == NULL) return;
    inOrderPrint(node->left);
    printf("%d ", node->val);
    inOrderPrint(node->right);
}

void postOrderPrint(bstNode* node) { // prints the post-order traversal of the BST
    if (node == NULL) return;
    postOrderPrint(node->left);
    postOrderPrint(node->right);
    printf("%d ", node->val);
}

int main() {   
    bstNode* root = NULL;
    root = insertNode(root, 50);    root = insertNode(root, 30);    root = insertNode(root, 20);    
    root = insertNode(root, 40);    root = insertNode(root, 70);    root = insertNode(root, 60);    
    root = insertNode(root, 80);
    printf("\nPreorder traversal of the BST: "); preOrderPrint(root); printf("\n");
    printf("Inorder traversal of the BST: "); inOrderPrint(root); printf("\n");
    printf("Postorder traversal of the BST: "); postOrderPrint(root); printf("\n");
    return 0;
}