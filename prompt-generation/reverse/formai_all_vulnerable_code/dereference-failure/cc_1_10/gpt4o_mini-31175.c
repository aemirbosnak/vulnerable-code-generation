//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary search tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to search for a value in the BST
bool search(struct Node* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// In-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value in the BST
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    int values[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Perform in-order traversal
    printf("In-order Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for some values
    int searchValues[] = {10, 19};
    for (int i = 0; i < 2; i++) {
        if (search(root, searchValues[i]))
            printf("%d found in the BST.\n", searchValues[i]);
        else
            printf("%d not found in the BST.\n", searchValues[i]);
    }

    // Delete a value and display the in-order traversal again
    printf("Deleting 10...\n");
    root = deleteNode(root, 10);
    printf("In-order Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);
    return 0;
}