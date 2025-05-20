//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary search tree (BST) node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to search for a value in the binary search tree
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Function to find the minimum value in the binary search tree
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to destroy the binary search tree and free memory
void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary search tree operations
int main() {
    Node* root = NULL;

    // Inserting values into the BST
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        root = insertNode(root, data[i]);
    }

    printf("In-order traversal of the binary search tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Searching for values
    int valuesToSearch[] = {30, 90, 70};
    for (int i = 0; i < sizeof(valuesToSearch)/sizeof(valuesToSearch[0]); i++) {
        if (search(root, valuesToSearch[i])) {
            printf("%d found in the BST.\n", valuesToSearch[i]);
        } else {
            printf("%d not found in the BST.\n", valuesToSearch[i]);
        }
    }

    // Deleting a node
    printf("Deleting node 20:\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    // Destroy the tree to free memory
    destroyTree(root);
    return 0;
}