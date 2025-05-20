//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for each node in the BST
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node in the BST
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    
    return node;
}

// Function to search for a value in the BST
struct Node* search(struct Node* node, int value) {
    if (node == NULL || node->data == value) {
        return node;
    }
    
    if (value < node->data) {
        return search(node->left, value);
    }
    
    return search(node->right, value);
}

// Function for In-Order Traversal of the BST
void inOrderTraversal(struct Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

// Function for Pre-Order Traversal of the BST
void preOrderTraversal(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

// Function for Post-Order Traversal of the BST
void postOrderTraversal(struct Node* node) {
    if (node != NULL) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
}

// Function to find the minimum value node in the tree
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // This is the node to be deleted
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

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;
    
    // Inserting values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");
    
    // Searching for a value
    int searchValue = 60;
    struct Node* foundNode = search(root, searchValue);
    if (foundNode) {
        printf("Found %d in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }
    
    // Deleting a node
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("In-Order Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");
    
    // Clean up the memory
    // Ideally would implement a function to free all nodes
    return 0;
}