//FormAI DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // defining a struct node
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BST { // defining a struct for a binary search tree
    TreeNode *root;
} BST;

void insert(BST *bst, int data) { // function to insert a node in the binary search tree

    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode)); // dynamically allocating memory for the node
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if (bst->root == NULL) { // if the root is NULL, node becomes root
        bst->root = node;
    }
    else {
        TreeNode *temp = bst->root;
        while (1) {
            if (data < temp->data) { // if the data to be inserted is less than the current node's data
                if (temp->left == NULL) { // check if left child is NULL, then insert at left
                    temp->left = node;
                    return;
                }
                else {
                    temp = temp->left;
                }
            }
            else { // if the data to be inserted is greater than or equal to the current node's data
                if (temp->right == NULL) { // check if right child is NULL, then insert at right
                    temp->right = node;
                    return;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}

void traverse(TreeNode *node) { // function to traverse the binary search tree in in-order traversal

    if (node != NULL) {
        traverse(node->left);
        printf("%d ", node->data);
        traverse(node->right);
    }
}

int main() {

    BST *bst = (BST*)malloc(sizeof(BST)); // dynamically allocating memory for the binary search tree
    bst->root = NULL;

    insert(bst, 50); // inserting nodes in the binary search tree
    insert(bst, 30);
    insert(bst, 70);
    insert(bst, 20);
    insert(bst, 40);
    insert(bst, 60);
    insert(bst, 80);

    printf("In-Order Traversal: ");
    traverse(bst->root); // traversing the binary search tree in in-order traversal

    return 0;
}