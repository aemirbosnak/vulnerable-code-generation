//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Struct for a Binary Search Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed while creating node!");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the root is empty, create a new node
        return createNode(data);
    }
    
    // Insert in the left subtree or right subtree based on value
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicates are not allowed
        fprintf(stderr, "Attempted to insert duplicate value: %d\n", data);
    }
    
    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater - search in the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller - search in the left subtree
    return search(root->left, key);
}

// Helper function to perform in-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Attempted to delete a node that doesn't exist: %d\n", key);
        return root;
    }

    // Find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to free the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main program to demonstrate the Binary Search Tree
int main() {
    struct Node* root = NULL;
    
    int numbers[] = {20, 10, 30, 5, 15, 25, 35};
    int i;
    
    // Insert numbers into the BST
    for (i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        root = insert(root, numbers[i]);
    }

    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Searching for a value
    int searchKey = 15;
    struct Node* result = search(root, searchKey);
    if (result != NULL) {
        printf("Found node with value: %d\n", searchKey);
    } else {
        printf("Node with value: %d not found\n", searchKey);
    }

    // Deleting a node
    int deleteKey = 10;
    printf("Deleting node with value: %d\n", deleteKey);
    root = deleteNode(root, deleteKey);
    
    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");
    
    // Free the allocated memory for the tree
    freeTree(root);
    return 0;
}