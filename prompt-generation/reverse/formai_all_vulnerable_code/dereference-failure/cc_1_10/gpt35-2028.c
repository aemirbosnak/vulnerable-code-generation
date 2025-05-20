//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

/* define the structure of a node */
struct node {
    int value;
    struct node *left;
    struct node *right;
};

/* create a new node with a given value */
struct node *createNode(int value) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* insert a new node with a given value in the binary search tree */
struct node *insertNode(struct node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

/* search for a given value in the binary search tree */
struct node *searchNode(struct node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (root->value < value) {
        return searchNode(root->right, value);
    }
    return searchNode(root->left, value);
}

/* display the contents of the binary search tree in inorder traversal */
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

int main() {
    int values[] = {15, 6, 3, 16, 20, 10, 13, 7, 5};
    struct node *root = NULL;
    
    /* insert nodes into the binary search tree */
    int i;
    for (i = 0; i < 9; i++) {
        root = insertNode(root, values[i]);
    }
    
    /* perform search for a node */
    struct node *searchResult = searchNode(root, 16);
    if (searchResult == NULL) {
        printf("Node not found\n");
    }
    else {
        printf("Node found: %d\n", searchResult->value);
    }
    
    /* display the contents of the binary search tree */
    printf("Contents of Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");
    
    /* free up the memory allocated to the nodes */
    free(searchResult);
    free(root);
    return 0;
}