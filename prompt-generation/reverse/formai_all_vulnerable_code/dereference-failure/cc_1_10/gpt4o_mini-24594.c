//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Search Tree node
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new node
struct BSTNode* createNode(int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the Binary Search Tree
struct BSTNode* insertNode(struct BSTNode* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) return createNode(data);

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Return the unchanged node pointer
    return root;
}

// Function for in-order traversal of the tree
void inOrderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to search for a value in the Binary Search Tree
struct BSTNode* searchNode(struct BSTNode* root, int data) {
    // Base Cases: root is null or data is present at root
    if (root == NULL || root->data == data) return root;

    // Value is greater than root's data
    if (data > root->data) return searchNode(root->right, data);

    // Value is less than root's data
    return searchNode(root->left, data);
}

// Function to find the minimum value node in the tree
struct BSTNode* minValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the Binary Search Tree
struct BSTNode* deleteNode(struct BSTNode* root, int data) {
    // Base case
    if (root == NULL) return root;

    // Recur down the tree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        struct BSTNode* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to free the Binary Search Tree
void freeTree(struct BSTNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the Binary Search Tree operations
int main() {
    struct BSTNode* root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // In-order traversal
    printf("In-order traversal of the created BST:\n");
    inOrderTraversal(root);
    printf("\n");

    // Search for a node
    int searchValue = 40;
    struct BSTNode* foundNode = searchNode(root, searchValue);
    if (foundNode != NULL) {
        printf("Node %d found in the BST.\n", searchValue);
    } else {
        printf("Node %d not found in the BST.\n", searchValue);
    }

    // Delete a node
    printf("Deleting node %d from the BST.\n", searchValue);
    root = deleteNode(root, searchValue);

    // In-order traversal after deletion
    printf("In-order traversal after deletion:\n");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);

    return 0;
}