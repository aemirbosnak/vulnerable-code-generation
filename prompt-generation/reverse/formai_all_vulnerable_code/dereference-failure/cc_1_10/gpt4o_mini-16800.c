//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
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
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to do inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function demonstrating the binary search tree operations
int main() {
    struct Node* root = NULL;

    // Sample data to insert into the BST
    int dataArray[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(dataArray) / sizeof(dataArray[0]);

    // Inserting data into the binary search tree
    for (int i = 0; i < size; i++) {
        root = insert(root, dataArray[i]);
    }

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting a node
    printf("Deleting 20 (leaf node)\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting another node
    printf("Deleting 30 (node with one child)\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting another node
    printf("Deleting 50 (node with two children)\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}