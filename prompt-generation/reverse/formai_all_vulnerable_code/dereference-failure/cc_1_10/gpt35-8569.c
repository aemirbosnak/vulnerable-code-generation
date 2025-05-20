//FormAI DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* Create a new Tree Node */
TreeNode* NewTreeNode(int value){
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Pre Order Traversal */
void PreOrder(TreeNode* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

/* In Order Traversal */
void InOrder(TreeNode* root){
    if(root == NULL) return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

/* Post Order Traversal */
void PostOrder(TreeNode* root){
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    TreeNode* root = NewTreeNode(1);
    root->left = NewTreeNode(2);
    root->right = NewTreeNode(3);
    root->left->left = NewTreeNode(4);
    root->left->right = NewTreeNode(5);
    printf("Pre-Order Traversal: ");
    PreOrder(root);
    printf("\nIn-Order Traversal: ");
    InOrder(root);
    printf("\nPost-Order Traversal: ");
    PostOrder(root);
    printf("\n");
    return 0;
}