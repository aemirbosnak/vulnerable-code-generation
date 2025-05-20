//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the node in our Cyberpunk-inspired binary search tree
struct Node {
    char name[50];  // The name of the cyber entity
    int id;         // Unique ID for the entity
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int id, const char *name) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int id, const char *name) {
    if (root == NULL) {
        return createNode(id, name);
    }
    if (id < root->id) {
        root->left = insert(root->left, id, name);
    } else if (id > root->id) {
        root->right = insert(root->right, id, name);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}

// Function to perform an in-order traversal of the tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Entity ID: %d, Name: %s\n", root->id, root->name);
        inOrderTraversal(root->right);
    }
}

// Function to free all nodes in the binary search tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    struct Node *root = NULL;
    
    // Welcome to the Neon City Database
    printf("=== Welcome to the Neon City Cyber Database ===\n");
    printf("Storing cyber entities in a digital realm...\n\n");

    // Sample data of cyber entities
    root = insert(root, 1, "Neon Assassin");
    insert(root, 3, "Cyber Hacker");
    insert(root, 2, "Virtual Saboteur");
    insert(root, 5, "Augmented Human");
    insert(root, 4, "Tech Sorcerer");

    // Display contents of the tree
    printf("In-Order Listing of Cyber Entities:\n");
    inOrderTraversal(root);
    printf("\n");

    // Searching for a specific entity by ID
    int searchId = 3;
    struct Node* searchResult = search(root, searchId);
    if (searchResult != NULL) {
        printf("Search Result: Found Entity ID: %d, Name: %s\n", searchResult->id, searchResult->name);
    } else {
        printf("Search Result: Entity with ID %d not found.\n", searchId);
    }

    // Clean up the memory
    freeTree(root);
    printf("Database cleanup complete. Shutting down...\n");
    return 0;
}