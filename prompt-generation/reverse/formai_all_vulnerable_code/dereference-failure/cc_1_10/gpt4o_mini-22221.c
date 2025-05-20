//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Node structure definition for the binary search tree (BST)
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
Node* insert(Node* root, int data) {
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
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    }
    
    return search(root->right, data);
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with the value found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to free up the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary search tree operations
int main() {
    Node* root = NULL;
    
    // Inserting values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Display the in-order traversal of the BST
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Searching for a value
    int searchValue = 40;
    Node* foundNode = search(root, searchValue);
    if (foundNode) {
        printf("Value %d found in the BST!\n", searchValue);
    } else {
        printf("Value %d not found in the BST.\n", searchValue);
    }

    // Deleting a node
    int deleteValue = 30;
    printf("Deleting value %d from the BST...\n", deleteValue);
    root = deleteNode(root, deleteValue);
    printf("In-order Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);
    
    return 0;
}