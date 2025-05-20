//FormAI DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Declare the structure for Binary Search Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search a node in BST
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value node in BST
struct Node* findMinNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the BST in In-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program to test the BST functions
int main() {
    struct Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 17);
    root = insertNode(root, 25);
    printf("In-order traversal of BST: ");
    inorder(root);
    printf("\n");
    struct Node* search_result = searchNode(root, 17);
    if (search_result == NULL) {
        printf("17 is not present in the BST.\n");
    }
    else {
        printf("17 is present in the BST.\n");
    }
    root = deleteNode(root, 20);
    printf("In-order traversal of BST after deletion of 20: ");
    inorder(root);
    printf("\n");
    return 0;
}