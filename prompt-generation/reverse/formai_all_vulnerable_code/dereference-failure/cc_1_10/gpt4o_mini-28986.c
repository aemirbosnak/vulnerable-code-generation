//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
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

// Function to find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find a node and delete it from the tree
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
        
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform a preorder traversal of the tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform a postorder traversal of the tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main driver function to execute the binary search tree operations
int main() {
    struct Node* root = NULL;
    int numbers[] = {50, 30, 20, 40, 70, 60, 80};
    int i;

    printf("Inserting values into the Binary Search Tree:\n");
    for (i = 0; i < 7; i++) {
        root = insert(root, numbers[i]);
        printf("%d ", numbers[i]);
    }

    printf("\n\nIn-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    printf("\nPre-order traversal of the BST:\n");
    preorderTraversal(root);
    printf("\n");

    printf("\nPost-order traversal of the BST:\n");
    postorderTraversal(root);
    printf("\n");

    printf("\nDeleting 20 (leaf node) from the BST:\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting 30 (node with one child) from the BST:\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    printf("\nDeleting 50 (node with two children) from the BST:\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}