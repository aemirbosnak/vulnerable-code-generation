//FormAI DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the tree
struct node* insert(struct node* root, int item) {
    // If the root is empty, create a new node with the given data
    if (root == NULL) {
        return createNode(item);
    }
    // If the new data is smaller than the root, insert the node at the left subtree
    if (item < root->data) {
        root->left = insert(root->left, item);
    }
    // If the new data is greater than the root, insert the node at the right subtree
    else if (item > root->data) {
        root->right = insert(root->right, item);
    }
    // Return the tree after new node insertion
    return root;
}

// Traverse the tree in-order
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Search for a specific node in the tree
struct node* search(struct node* root, int item) {
    // If the root is empty or has the item value, return the root
    if (root == NULL || root->data == item) {
        return root;
    }
    // If the item is greater than the root, go to the right subtree
    else if (root->data < item) {
        return search(root->right, item);
    }
    // If the item is smaller than the root, go to the left subtree
    else {
        return search(root->left, item);
    }
}

// Find the minimum value in the tree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a node from the tree
struct node* deleteNode(struct node* root, int item) {
    // Base case
    if (root == NULL) {
        return root;
    }
    // If the item is smaller than the root, delete it at the left subtree
    if (item < root->data) {
        root->left = deleteNode(root->left, item);
    }   
    // If the item is greater than the root, delete it at the right subtree
    else if (item > root->data) {
        root->right = deleteNode(root->right, item);
    }
    // If the item is found, delete it
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert 10 nodes into the tree
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 50);
    insert(root, 10);
    insert(root, 40);
    insert(root, 60);
    insert(root, 5);
    insert(root, 15);
    insert(root, 35);
    insert(root, 45);

    // Print the in-order traversal of the tree
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search the tree for node with value 15
    struct node* result = search(root, 15);
    if (result == NULL) {
        printf("Node with value 15 not found\n");
    }
    else {
        printf("Node with value 15 found\n");
    }

    // Delete node with value 10 and print the in-order traversal of the tree again
    root = deleteNode(root, 10);
    printf("In-order traversal after deleting node with value 10: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}