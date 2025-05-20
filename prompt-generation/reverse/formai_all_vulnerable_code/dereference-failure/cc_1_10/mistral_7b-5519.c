//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the tree node structure
typedef struct Node {
    int key;
    char name[20];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given key and name
Node* newNode(int key, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform a binary search and return the corresponding node
Node* search(Node* root, int key) {
    Node* current = root;

    // Search until the node is found or the search tree is empty
    while (current != NULL) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            // Key found, return the node
            return current;
        }
    }

    // Key not found, return NULL
    return NULL;
}

// Function to insert a new node with the given key and name into the tree
Node* insert(Node* root, int key, char* name) {
    if (root == NULL) {
        return newNode(key, name);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, name);
    } else if (key > root->key) {
        root->right = insert(root->right, key, name);
    }

    return root;
}

// Function to print the tree in a visually appealing way
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("-(%d) %s\n", root->key, root->name);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

// Main function to demonstrate the usage of the binary search tree
int main() {
    // Seed the random number generator for reproducibility
    srand(time(NULL));

    // Create an empty tree
    Node* root = NULL;

    // Insert some nodes with random keys and names
    for (int i = 0; i < 10; i++) {
        int key = rand() % 50 + 1;
        char name[20];
        sprintf(name, "Person %d", i + 1);
        root = insert(root, key, name);
    }

    // Print the tree in a visually appealing way
    printTree(root, 0);

    // Perform a search for a random key
    int searchKey = rand() % 50 + 1;
    Node* searchResult = search(root, searchKey);

    if (searchResult != NULL) {
        printf("Found node with key %d and name %s\n", searchResult->key, searchResult->name);
    } else {
        printf("Key %d not found\n", searchKey);
    }

    return 0;
}