//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } 
    return search(root->right, key);
}

// Function to perform inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
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
        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function to demonstrate the binary search tree
int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Inorder traversal
    printf("Inorder traversal of the BST:\n");
    inorder(root);
    printf("\n");

    // Search for a node
    int key = 40;
    struct Node* searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Node %d found in the BST.\n", key);
    } else {
        printf("Node %d not found in the BST.\n", key);
    }

    // Delete a node
    printf("Deleting node 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    // Clean up remaining nodes
    while (root != NULL) {
        root = deleteNode(root, root->key);
    }
    
    return 0;
}