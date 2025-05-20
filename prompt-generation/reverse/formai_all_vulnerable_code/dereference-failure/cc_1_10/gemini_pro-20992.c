//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
// Let's include some essential headers
#include <stdio.h>
#include <stdlib.h>

// Defining our binary search tree node
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Welcome to our tree-creating function!
BSTNode *createNode(int newData) {
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Time to insert some data into our tree!
BSTNode *insertNode(BSTNode *root, int newData) {
    if (root == NULL) {
        return createNode(newData);
    } else if (newData < root->data) {
        root->left = insertNode(root->left, newData);
    } else {
        root->right = insertNode(root->right, newData);
    }
    return root;
}

// Ready to traverse our binary search tree?
void inOrderTraversal(BSTNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// We're on a mission to find the smallest value in the tree!
BSTNode *findMinNode(BSTNode *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Let's delete a node from our tree and maintain its integrity.
BSTNode *deleteNode(BSTNode *root, int deleteData) {
    if (root == NULL) {
        return NULL;
    }
    if (deleteData < root->data) {
        root->left = deleteNode(root->left, deleteData);
    } else if (deleteData > root->data) {
        root->right = deleteNode(root->right, deleteData);
    } else {
        if (root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        BSTNode *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Let's test our BST in action!
int main() {
    // Creating our root node
    BSTNode *root = NULL;

    // Inserting some data into the tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Traversing the tree in order to see our sorted data
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Searching for the smallest value in the tree
    BSTNode *minNode = findMinNode(root);
    printf("Minimum value in the tree: %d\n", minNode->data);

    // Deleting the root node from the tree
    root = deleteNode(root, 50);

    // Traversing the tree again to see the updated data
    printf("In-order traversal after deleting the root: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}