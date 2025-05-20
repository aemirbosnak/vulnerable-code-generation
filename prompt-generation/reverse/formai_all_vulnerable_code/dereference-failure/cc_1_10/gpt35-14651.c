//FormAI DATASET v1.0 Category: Binary search trees ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

// Defining a binary search tree node structure
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new binary search tree node with the given data
struct BSTNode* createNode(int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node with the given data into the binary search tree rooted at the given node
struct BSTNode* insert(struct BSTNode* root, int data) {
    if(root == NULL) {
        root = createNode(data);
    }
    else if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to print the binary search tree in inorder traversal
void inorderTraversal(struct BSTNode* root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to find the node with the minimum value in the binary search tree rooted at the given node
struct BSTNode* findMinimumNode(struct BSTNode* node) {
    if(node == NULL) {
        return NULL;
    }
    else if(node->left == NULL) {
        return node;
    }
    else {
        return findMinimumNode(node->left);
    }
}

// Function to delete a node with the given data from the binary search tree rooted at the given node
struct BSTNode* delete(struct BSTNode* root, int data) {
    if(root == NULL) {
        return root;
    }
    if(data < root->data) {
        root->left = delete(root->left, data);
    }
    else if(data > root->data) {
        root->right = delete(root->right, data);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL) {
            struct BSTNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct BSTNode* temp = root;
            root = root->left;
            free(temp);
        }
        else {
            struct BSTNode* temp = findMinimumNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct BSTNode* root = NULL;
    
    // Inserting nodes into the binary search tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 50);
    
    printf("Inorder traversal of the binary search tree before deleting any nodes : ");
    inorderTraversal(root);
    
    // Deleting nodes from the binary search tree
    root = delete(root, 10);
    root = delete(root, 30);
    root = delete(root, 50);
    
    printf("\n\nInorder traversal of the binary search tree after deleting nodes : ");
    inorderTraversal(root);
    
    return 0;
}