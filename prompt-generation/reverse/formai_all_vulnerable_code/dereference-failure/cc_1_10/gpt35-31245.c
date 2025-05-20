//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define Binary Search Tree Node Structure
struct BSTNode {
    int data ;
    struct BSTNode *left ;
    struct BSTNode *right ;
} ;

// Function to create new Binary Search Tree Node
struct BSTNode *createBSTNode (int data) {
    struct BSTNode *newBSTNode = (struct BSTNode*) malloc (sizeof(struct BSTNode)) ;
    newBSTNode->data = data ;
    newBSTNode->left = NULL ;
    newBSTNode->right = NULL ;
    return newBSTNode ;
}

// Function to insert a new node in Binary Search Tree
struct BSTNode *insertNodeInBST (struct BSTNode *root, int data) {
    if (root == NULL) {
        root = createBSTNode (data) ;
    }
    else if (data <= root->data) {
        root->left = insertNodeInBST (root->left, data) ;
    }
    else {
        root->right = insertNodeInBST (root->right, data) ;
    }
    return root ;
}

// Function to search a node in Binary Search Tree
struct BSTNode *searchNodeInBST (struct BSTNode *root, int key) {
    if (root == NULL || root->data == key) {
        return root ;
    }
    else if (key < root->data) {
        return searchNodeInBST (root->left, key) ;
    }
    else {
        return searchNodeInBST (root->right, key) ;
    }
}

// Function to find minimum value node in Binary Search Tree
struct BSTNode *findMinimumValueNodeInBST (struct BSTNode *root) {
    struct BSTNode *currentNode = root ;
    while (currentNode->left != NULL) {
        currentNode = currentNode->left ;
    }
    return currentNode ;
}

// Function to delete a node from Binary Search Tree
struct BSTNode *deleteNodeFromBST (struct BSTNode *root, int key) {
    if (root == NULL) {
        return root ;
    }
    else if (key < root->data) {
        root->left = deleteNodeFromBST (root->left, key) ;
    }
    else if (key > root->data) {
        root->right = deleteNodeFromBST (root->right, key) ;
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free (root) ;
            root = NULL ;
        }
        else if (root->left == NULL) {
            struct BSTNode *temp = root ;
            root = root->right ;
            free (temp) ;
        }
        else if (root->right == NULL) {
            struct BSTNode *temp = root ;
            root = root->left ;
            free (temp) ;
        }
        else {
            struct BSTNode *temp = findMinimumValueNodeInBST (root->right) ;
            root->data = temp->data ;
            root->right = deleteNodeFromBST (root->right, temp->data) ;
        }
    }
    return root ;
}

// Function to traverse Binary Search Tree in Inorder manner
void traverseInorderBST (struct BSTNode *root) {
    if (root == NULL) {
        return ;
    }
    traverseInorderBST (root->left) ;
    printf ("%d ", root->data) ;
    traverseInorderBST (root->right) ;
}

// Main Function
int main () {
    struct BSTNode *root = NULL ;
    
    // Insert some sample nodes to Binary Search Tree
    root = insertNodeInBST (root, 5) ;
    root = insertNodeInBST (root, 3) ;
    root = insertNodeInBST (root, 7) ;
    root = insertNodeInBST (root, 1) ;
    root = insertNodeInBST (root, 9) ;
    root = insertNodeInBST (root, 4) ;
    root = insertNodeInBST (root, 6) ;
    
    // Traverse Binary Search Tree in Inorder manner
    printf ("Binary Search Tree Inorder Traversal: ") ;
    traverseInorderBST (root) ;
    printf ("\n") ;
    
    // Search a node in Binary Search Tree
    struct BSTNode *searchNode = searchNodeInBST (root, 4) ;
    if (searchNode == NULL) {
        printf ("Node Not Found in Binary Search Tree\n") ;
    }
    else {
        printf ("Node Found in Binary Search Tree (%d)\n", searchNode->data) ;
    }
    
    // Delete a node from Binary Search Tree
    root = deleteNodeFromBST (root, 4) ;
    
    // Traverse Binary Search Tree in Inorder manner
    printf ("Binary Search Tree Inorder Traversal (After Deleting Node): ") ;
    traverseInorderBST (root) ;
    printf ("\n") ;
    
    return 0 ;
}