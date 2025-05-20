//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
struct Node {
    int data;  // Data held by the node
    struct Node* left;  // Left child pointer
    struct Node* right; // Right child pointer
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL;
    return newNode; 
}

// Function to insert data into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        // Creating a new node if root is NULL
        return createNode(value); 
    }
    if (value < root->data) {
        // Insert in the left subtree
        root->left = insert(root->left, value); 
    } else if (value > root->data) {
        // Insert in the right subtree
        root->right = insert(root->right, value); 
    }
    return root; 
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root; 
    }
    // Search in the left or right subtree based on value
    if (value < root->data) {
        return search(root->left, value); 
    }
    return search(root->right, value); 
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);        // Visit left subtree
        printf("%d ", root->data);       // Visit node
        inorderTraversal(root->right);       // Visit right subtree
    }
}

// Function to create a random number for demonstration
int randomValue() {
    return rand() % 100; // Returns a random value between 0 and 99
}

// Main function
int main() {
    struct Node* root = NULL;  // Start with an empty BST

    // Excitedly inserting random values into the BST!
    printf("Inserting random values into the Binary Search Tree:\n");
    for (int i = 0; i < 10; i++) {
        int value = randomValue();
        printf("Inserting: %d\n", value);
        root = insert(root, value);
    }

    // Time for some in-order traversal action!
    printf("\nIn-order Traversal of the Binary Search Tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Now let’s do some searching!
    int searchValue;
    printf("Enter a number to search in the BST: ");
    scanf("%d", &searchValue);
    struct Node* searchResult = search(root, searchValue);

    if (searchResult) {
        printf("Yay! %d is found in the BST!\n", searchValue);
    } else {
        printf("Oh no! %d is not found in the BST!\n", searchValue);
    }

    // Free up allocated memory (optional step)
    printf("\nFreeing memory and exiting...\n");
    // Implementing memory freeing is crucial if we were to develop further!

    // Exit program
    return 0; 
}