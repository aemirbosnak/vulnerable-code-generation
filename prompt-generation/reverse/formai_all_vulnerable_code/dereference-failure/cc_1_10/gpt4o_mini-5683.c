//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Search Tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to search a key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) {
        return root;
    }

    // Key is greater than root's key
    if (key > root->key) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// In-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a specific key
    int searchKey = 60;
    struct Node* foundNode = search(root, searchKey);
    if (foundNode != NULL) {
        printf("Node with key %d found in the BST.\n", searchKey);
    } else {
        printf("Node with key %d not found in the BST.\n", searchKey);
    }

    // Free the allocated memory
    freeTree(root);
    
    // Concluding message to reflect on the tranquility of the code
    printf("Thank you for exploring this peaceful Binary Search Tree.\n");
    return 0;
}