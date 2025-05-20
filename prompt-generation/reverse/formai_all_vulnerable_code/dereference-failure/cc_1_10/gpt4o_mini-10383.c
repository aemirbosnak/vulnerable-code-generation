//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the Binary Search Tree (BST)
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to search for a given value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value in the BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver program to demonstrate the BST functions
int main() {
    struct Node *root = NULL;

    // Let's get the party started!
    printf("Welcome to the Awesome Binary Search Tree Demo!\n");
    
    // Inserting nodes
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Inserting values into the BST:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserting %d...\n", values[i]);
        root = insert(root, values[i]);
    }
    
    // In-order traversal
    printf("In-order traversal of the BST:\n");
    inOrderTraversal(root);
    printf("\n");

    // Searching for a value
    int searchValue = 60;
    printf("Searching for %d in the BST:\n", searchValue);
    struct Node *foundNode = search(root, searchValue);
    if (foundNode != NULL) {
        printf("Found %d in the BST!\n", foundNode->data);
    } else {
        printf("%d not found in the BST!\n", searchValue);
    }

    // Deleting a node
    int deleteValue = 20;
    printf("Attempting to delete %d from the BST...\n", deleteValue);
    root = deleteNode(root, deleteValue);
    printf("In-order traversal after deleting %d:\n", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    // Free resources
    printf("Cleaning up nodes...\n");
    free(root);

    // End the show!
    printf("Thank you for joining the Binary Search Tree Demo! Bye!\n");
    return 0;
}