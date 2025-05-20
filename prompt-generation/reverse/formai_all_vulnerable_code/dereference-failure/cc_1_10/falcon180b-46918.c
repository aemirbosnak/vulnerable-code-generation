//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

// define the structure of a node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// define the structure of a binary search tree
struct bst {
    struct node* root;
};

// function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to create an empty binary search tree
struct bst* createBST() {
    struct bst* bst = (struct bst*)malloc(sizeof(struct bst));
    bst->root = NULL;
    return bst;
}

// function to insert a node into the binary search tree
void insertNode(struct node** nodeRef, int data) {
    if (*nodeRef == NULL) {
        *nodeRef = newNode(data);
    } else if (data < (*nodeRef)->data) {
        insertNode(&(*nodeRef)->left, data);
    } else {
        insertNode(&(*nodeRef)->right, data);
    }
}

// function to search for a node in the binary search tree
struct node* searchNode(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// function to print the binary search tree in order
void printBST(struct node* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    printf("%d ", root->data);
    printBST(root->right);
}

// main function to test the binary search tree implementation
int main() {
    // create an empty binary search tree
    struct bst* bst = createBST();

    // insert nodes into the binary search tree
    insertNode(&bst->root, 10);
    insertNode(&bst->root, 5);
    insertNode(&bst->root, 15);
    insertNode(&bst->root, 2);
    insertNode(&bst->root, 7);
    insertNode(&bst->root, 12);
    insertNode(&bst->root, 17);

    // print the binary search tree in order
    printf("Binary Search Tree in Order:\n");
    printBST(bst->root);

    // search for a node in the binary search tree
    struct node* searchResult = searchNode(bst->root, 7);
    if (searchResult!= NULL) {
        printf("\nNode with data %d found!\n", searchResult->data);
    } else {
        printf("\nNode with data %d not found.\n", 7);
    }

    return 0;
}