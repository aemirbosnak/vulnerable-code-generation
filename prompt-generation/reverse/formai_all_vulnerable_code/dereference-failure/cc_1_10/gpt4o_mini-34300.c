//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Introducing our BST Node, who loves to hold numbers like trophies!
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Node %d has been born! 🎉\n", data);
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // Found a home for the new node!
        return createNode(data);
    }

    // Our ever-judgmental tree will guide us where to go
    if (data < root->data) {
        printf("Going left from %d\n", root->data);
        root->left = insert(root->left, data);
    } else {
        printf("Going right from %d\n", root->data);
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal (It’s like a friendly neighborhood stroll)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Visiting node with value %d... (Hello! 👋)\n", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root; // We've found our prize!
    }
    
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Let the party commence! Deletion time!
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left; // Going on a mini-adventure to find min value
    }
    return current;
}

// Deleting a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Oops! Node %d could not be found for deletion!\n", data);
        return root;
    }

    if (data < root->data) {
        printf("Looking for node %d on the left side...\n", data);
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        printf("Looking for node %d on the right side...\n", data);
        root->right = deleteNode(root->right, data);
    } else {
        printf("Found node %d! Time to say goodbye! 😢\n", data);
        
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // If the node has two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Clean up and free the memory, it's like saying thank you!
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        printf("Node %d has been released into the wild! 🦁\n", root->data);
        free(root);
    }
}

// Our main film with a twist!
int main() {
    struct Node* root = NULL;
    
    int numbers[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    printf("🎬 Welcome to the Binary Search Tree Show! 🎬\n");
    for (int i = 0; i < n; i++) {
        root = insert(root, numbers[i]);
    }

    printf("🌳 Inorder Traversal of BST: \n");
    inorderTraversal(root);

    printf("\n🔍 Searching for 60...\n");
    struct Node* foundNode = search(root, 60);
    if (foundNode) {
        printf("Node 60 has been found! 🎉\n");
    } else {
        printf("Node 60 is not in our party! 🚫\n");
    }

    printf("\n🗑️ Deleting node 20...\n");
    root = deleteNode(root, 20);
    
    printf("🌳 Inorder Traversal after deletion: \n");
    inorderTraversal(root);
    
    // Remember to clean up after the show!
    freeTree(root);
    printf("🎉 Thank you for attending! All nodes have left the building! 🎉\n");
    
    return 0;
}