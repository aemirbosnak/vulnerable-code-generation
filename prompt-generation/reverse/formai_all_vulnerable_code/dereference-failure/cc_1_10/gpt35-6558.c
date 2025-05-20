//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
// This program demonstrates the implementation of a Binary Search Tree (BST) in C
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNewNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a Node in the BST
struct Node* insertNode(struct Node* root, int data) {
    // If the tree is empty, return a new Node
    if(root == NULL) {
        return createNewNode(data);
    }
    // Otherwise, recur down the tree
    if(data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // Return the unchanged node pointer
    return root;
}

// Function to search for a Node in the BST
struct Node* searchNode(struct Node* root, int data) {
    // If the root is null or the data is present at root
    if(root == NULL || root->data == data) {
        return root;
    }
    // If data is greater than root's data, recur down right subtree
    if(root->data < data) {
        return searchNode(root->right, data);
    }
    // Else, recur down left subtree
    return searchNode(root->left, data);
}

// Function to find the inorder successor of the given Node
struct Node* inorderSuccessor(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a Node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    // Base case
    if(root == NULL) {
        return root;
    }
    // If the data to be deleted is smaller than root's data,
    // then it lies in left subtree
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than root's data,
    // then it lies in right subtree
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is same as root's data, then this is the Node
    // to be deleted
    else {
        // Node with only one child or no child
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = inorderSuccessor(root->right);
        // Copy the inorder successor's content to this Node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the Nodes in inorder traversal
void inorderTraversal(struct Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d, ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    // Insert Nodes into the BST
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    
    printf("BST before deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    // Delete a Node from the BST
    root = deleteNode(root, 6);
    
    printf("BST after deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    // Search for a Node in the BST
    struct Node* searchedNode = searchNode(root, 10);
    if(searchedNode != NULL) {
        printf("Searched Node found: %d\n", searchedNode->data);
    }
    else {
        printf("Searched Node not found!\n");
    }

    return 0;
}