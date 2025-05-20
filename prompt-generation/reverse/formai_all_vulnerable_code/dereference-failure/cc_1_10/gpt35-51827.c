//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

//Struct to represent a node in a binary tree
typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

//Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a new node in the binary tree
TreeNode* insertNode(TreeNode* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->value)
        root->left = insertNode(root->left, value);
    else if(value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

//Function to print the binary tree in a sideways orientation
void printTree(TreeNode* root, int depth) {
    if(root == NULL)
        return;
    printTree(root->right, depth + 1);
    for(int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", root->value);
    printTree(root->left, depth + 1);
}

int main() {
    TreeNode* root = NULL;

    //Inserting nodes in the binary tree
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 9);
    root = insertNode(root, 2);
    root = insertNode(root, 5);
    root = insertNode(root, 8);
    root = insertNode(root, 10);
    root = insertNode(root, 4);
    root = insertNode(root, 6);

    //Printing the binary tree visually using a sideways orientation
    printf("\nBinary Tree Visualization:\n\n");
    printTree(root, 0);

    return 0;
}