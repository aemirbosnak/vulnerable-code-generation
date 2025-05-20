//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
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

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
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

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the binary search tree memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function demonstrating the binary search tree operations
int main() {
    struct Node* root = NULL;

    // Inserting values into the binary search tree
    printf("Inserting values into the binary search tree:\n");
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++) {
        printf("Inserting %d...\n", values[i]);
        root = insert(root, values[i]);
    }

    // Displaying the inorder traversal of the binary search tree
    printf("\nInorder Traversal of the Binary Search Tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Searching for values in the binary search tree
    printf("Searching for values in the binary search tree:\n");
    int searchValues[] = {25, 40, 70};
    for (int i = 0; i < 3; i++) {
        struct Node* result = search(root, searchValues[i]);
        if (result != NULL) {
            printf("Found %d in the tree.\n", searchValues[i]);
        } else {
            printf("%d not found in the tree.\n", searchValues[i]);
        }
    }

    // Deleting a value from the binary search tree
    printf("\nDeleting value 20 from the binary search tree...\n");
    root = deleteNode(root, 20);
    printf("Inorder Traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);
    return 0;
}