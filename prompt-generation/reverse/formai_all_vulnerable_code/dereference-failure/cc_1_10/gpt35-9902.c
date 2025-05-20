//FormAI DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdlib.h>
#include <stdio.h>

// Structure for the tree node
struct treeNode {
    int data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

// Function prototypes
void insert(struct treeNode **tree, int val);
void inorderTraverse(struct treeNode *tree);
void deleteTree(struct treeNode *tree);

// Main function
int main() {
    struct treeNode *tree = NULL;
    int arr[] = {10, 5, 15, 7, 12, 3, 8, 18};

    // Insert elements into tree
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        insert(&tree, arr[i]);
    }

    // Display tree
    printf("Inorder traversal of tree: ");
    inorderTraverse(tree);
    printf("\n");

    // Delete tree
    deleteTree(tree);

    return 0;
}

// Function to insert an element into the tree
void insert(struct treeNode **tree, int val) {
    if (*tree == NULL) {
        struct treeNode *newNode = (struct treeNode*) malloc(sizeof(struct treeNode));
        newNode->data = val;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        *tree = newNode;
    } else if (val < (*tree)->data) {
        insert(&((*tree)->leftChild), val);
    } else {
        insert(&((*tree)->rightChild), val);
    }
}

// Function to perform inorder traversal of tree
void inorderTraverse(struct treeNode *tree) {
    if (tree != NULL) {
        inorderTraverse(tree->leftChild);
        printf("%d ", tree->data);
        inorderTraverse(tree->rightChild);
    }
}

// Function to delete the tree from memory
void deleteTree(struct treeNode *tree) {
    if (tree != NULL) {
        deleteTree(tree->leftChild);
        deleteTree(tree->rightChild);
        free(tree);
    }
}