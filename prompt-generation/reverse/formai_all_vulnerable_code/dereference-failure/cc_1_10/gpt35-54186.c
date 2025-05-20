//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
 
/* Define a node struct for our tree */
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
/* Define a function to create a new node */
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
/* Define a function to insert a new node into the tree */
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    /* If root is NULL, create a new node and return it */
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    /* Traverse the left side of the tree if data is less than root */
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    /* Traverse the right side of the tree if data is greater than root */
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    /* Return the root unchanged */
    return root;
}
 
/* Define a function to search for a data element in the tree */
struct TreeNode* findNode(struct TreeNode* root, int data) {
    /* If root is NULL or data matches the root, return the root */
    if (root == NULL || root->data == data) {
        return root;
    }
    /* Traverse the left side of the tree if data is less than root */
    else if (data < root->data) {
        return findNode(root->left, data);
    }
    /* Traverse the right side of the tree if data is greater than root */
    else if (data > root->data) {
        return findNode(root->right, data);
    }
}

int main(void)
{
    /* Create the root of the tree */
    struct TreeNode* root = createNode(5);
    /* Insert some data elements into the tree */
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 9);
    root = insertNode(root, 6);
    /* Search for some data elements in the tree */
    struct TreeNode* result = findNode(root, 3);
    printf("Found data %d\n", result->data);
    result = findNode(root, 9);
    printf("Found data %d\n", result->data);
    result = findNode(root, 2);
    if (result == NULL) {
        printf("Data not found!\n");
    }
    /* Bonus points for cleaning up our memory! */
    free(root->left->left);
    free(root->left);
    free(root->right->left);
    free(root->right);
    free(root);
    return 0;
}