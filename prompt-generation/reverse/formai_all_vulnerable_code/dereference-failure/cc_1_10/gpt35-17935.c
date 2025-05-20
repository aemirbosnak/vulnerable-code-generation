//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to insert a new node into the binary search tree
struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) {
        // Create a new node if the tree is empty
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    // If the data is less than the current node's data, insert into the left subtree
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    // If the data is greater than or equal to the current node's data, insert into the right subtree
    else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to search for a node in the binary search tree
struct TreeNode* search(struct TreeNode* node, int data) {
    if (node == NULL || node->data == data) {
        // Return the node if it matches the data or if the node is NULL
        return node;
    }
    
    // Search the left subtree if the data is less than the current node's data
    if (data < node->data) {
        return search(node->left, data);
    }
    // Search the right subtree if the data is greater than the current node's data
    else {
        return search(node->right, data);
    }
}

// Function to delete a node from the binary search tree
struct TreeNode* delete(struct TreeNode* node, int data) {
    if (node == NULL) {
        // Return NULL if the node is not found
        return NULL;
    }
    
    // If the data is less than the current node's data, delete from the left subtree
    if (data < node->data) {
        node->left = delete(node->left, data);
    }
    // If the data is greater than the current node's data, delete from the right subtree
    else if (data > node->data) {
        node->right = delete(node->right, data);
    }
    // If the node is found, delete it
    else {
        // If the node has only one child or no children
        if (node->left == NULL) {
            struct TreeNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct TreeNode* temp = node->left;
            free(node);
            return temp;
        }
        
        // If the node has two children, find the inorder successor and replace the node
        struct TreeNode* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

// Function to print the binary search tree inorder
void inorder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    // Create a binary search tree and insert some nodes
    printf("Creating binary search tree...\n");
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Print the binary search tree inorder
    printf("Inorder traversal of binary search tree: ");
    inorder(root);
    printf("\n");
    
    // Search for some nodes in the binary search tree
    struct TreeNode* node = search(root, 60);
    if (node != NULL) {
        printf("Node with data %d found in binary search tree\n", node->data);
    }
    else {
        printf("Node not found in binary search tree\n");
    }
    
    node = search(root, 90);
    if (node != NULL) {
        printf("Node with data %d found in binary search tree\n", node->data);
    }
    else {
        printf("Node not found in binary search tree\n");
    }
    
    // Delete some nodes from the binary search tree
    printf("Deleting nodes from binary search tree...\n");
    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 60);
    
    // Print the binary search tree inorder
    printf("Inorder traversal of binary search tree: ");
    inorder(root);
    printf("\n");
    
    return 0;
}