//FormAI DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node
struct node* insert(struct node* root, int data) {
    // If the tree is empty, create a new node as root
    if (root == NULL) {
        return createNode(data);
    }

    // Traverse through the tree to find the correct position to insert the node
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Search for a node
struct node* search(struct node* root, int data) {
    // If the tree is empty or the node is found

    if (root == NULL || root->data == data) {
        return root;
    }

    // Traverse through the tree to find the desired node
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Find the minimum element
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Delete a node
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // Traverse through the tree to locate the desired node
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // If the node to be deleted has only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal of the tree
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert nodes into the tree
    root = insert(root, 16);
    root = insert(root, 8);
    root = insert(root, 24);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 28);

    // Print the inorder traversal
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node
    struct node* searchedNode = search(root, 12);
    if (searchedNode == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found: %d\n", searchedNode->data);
    }

    // Delete a node
    root = deleteNode(root, 8);

    // Print the inorder traversal after deletion
    printf("Inorder traversal of the BST after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}