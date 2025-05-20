//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Search Tree
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

// Function to insert a new node into the BST
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

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

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
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function for in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to print the tree in a visual format
void printTree(struct Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase space for the right child

    printTree(root->right, space); // Print right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data); // Print the current node

    printTree(root->left, space); // Print left child
}

// Main function to create the BST and perform operations
int main() {
    struct Node* root = NULL;
    
    // Inserting values into the BST
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal of the created BST:\n");
    inorderTraversal(root);
    printf("\n");

    // Searching for a value
    int searchValue = 60;
    struct Node* foundNode = search(root, searchValue);
    printf("Searching for value %d in the BST: %s\n", searchValue, foundNode != NULL ? "Found" : "Not Found");

    // Printing the tree
    printf("Visual representation of the BST:\n");
    printTree(root, 0);

    // Deleting a node
    int deleteValue = 70;
    printf("Deleting value %d from the BST...\n", deleteValue);
    root = deleteNode(root, deleteValue);
    
    printf("Inorder traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here for brevity, but recommended)
    // (Code to free nodes would go here)
    
    return 0;
}