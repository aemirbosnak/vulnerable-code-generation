//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// A node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to insert a new node with the given key
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Helper function to print the binary search tree inorder
void printInorder(struct Node* node) {
    if (node!= NULL) {
        printInorder(node->left);
        printf("%d ", node->key);
        printInorder(node->right);
    }
}

// Function to search for a key in the binary search tree
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (key == root->key) {
        return 1;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    // Create the root node
    struct Node* root = NULL;

    // Insert some nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 100);

    // Print the binary search tree inorder
    printf("Inorder traversal of the binary search tree:\n");
    printInorder(root);

    // Search for a key in the binary search tree
    printf("Search for key 60:\n");
    if (search(root, 60)) {
        printf("Key found!\n");
    } else {
        printf("Key not found.\n");
    }

    // Free the memory allocated for the nodes
    while (root!= NULL) {
        struct Node* temp = root;
        root = root->left;
        free(temp);
    }

    return 0;
}