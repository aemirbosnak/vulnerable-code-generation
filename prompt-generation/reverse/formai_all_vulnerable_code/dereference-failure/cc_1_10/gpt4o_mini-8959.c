//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// ** The TreeNode Structure ** 
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// ** Function Prototypes **
TreeNode* createNode(int data);
TreeNode* insert(TreeNode* root, int data);
void inorderTraversal(TreeNode* root);
void freeTree(TreeNode* root);

// ** Magical Function Absolute for Node Creation **
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ** The Gateway for Inserting a Node **
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// ** An Enchanting Function for In-Order Traversal **
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// ** A Gentle Cleanup for the Tree **
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// ** The Heart of the Program's Execution **
int main() {
    TreeNode* root = NULL; // The Root of our BST: Empty Nest

    // ** A Symphony of Insertion **
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // ** The In-Order Serpent Dance **
    printf("In-order Traversal of the Tree:\n");
    inorderTraversal(root);
    printf("\n");

    // ** A Beautiful Goodbye **
    freeTree(root);
    return 0; // ** Ending the Journey with Grace **
}

/*
   The Binary Search Tree we create reflects a world
   where every node sings in harmony, nestled in balance,
   and the in-order traversal reveals the beauty of order
   within the chaos of data. As we traverse from left,
   we gather echoes of the past, meet the present in center,
   and embrace the future in the right. 

   Each node, a story; each leaf, a memory - we venture forth 
   into a world where numbers tell tales and algorithms breathe life.
*/