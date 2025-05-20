//FormAI DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in binary search tree
typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} BSTNode;

// Function to create a new node in the BST
BSTNode* newNode(int data) {
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the BST
BSTNode* insert(BSTNode* node, int data) {
    if(node == NULL) {
        return newNode(data);
    }
    
    if(data < node->data) {
        node->left = insert(node->left, data);
    } else if(data > node->data) {
        node->right = insert(node->right, data);
    }
    
    return node;
}

// Function to search for a node in the BST
BSTNode* search(BSTNode* node, int data) {
    if(node == NULL) {
        return NULL;
    }
    
    if(data == node->data) {
        return node;
    } else if(data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

// Function to delete a node from the BST
BSTNode* delete(BSTNode* node, int data) {
    if(node == NULL) {
        return NULL;
    }
    
    if(data < node->data) {
        node->left = delete(node->left, data);
    } else if(data > node->data) {
        node->right = delete(node->right, data);
    } else {
        if(node->left == NULL) {
            BSTNode* temp = node->right;
            free(node);
            return temp;
        } else if(node->right == NULL) {
            BSTNode* temp = node->left;
            free(node);
            return temp;
        }
        
        BSTNode* temp = node->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    
    return node;
}

// Function to perform inorder traversal of BST
void inorder(BSTNode* node) {
    if(node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    BSTNode* root = NULL;
    
    // Insert nodes and create the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Inorder traversal of BST before deletion:\n");
    inorder(root);
    
    // Delete node with value 40 from the BST
    root = delete(root, 40);
    
    printf("\nInorder traversal of BST after deletion:\n");
    inorder(root);
    
    return 0;
}