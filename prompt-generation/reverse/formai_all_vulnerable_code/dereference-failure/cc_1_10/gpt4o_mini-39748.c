//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory for a new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the binary search tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } 
    return root; // return the unchanged node pointer
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum node in the binary search tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a key from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        struct Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to print the binary search tree in-order
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate the use of binary search tree
int main() {
    struct Node* root = NULL;
    
    // Inserting nodes
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("In-order traversal of the binary search tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Search for a specific key
    int searchKey = 40;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Key %d found in the binary search tree.\n", searchKey);
    } else {
        printf("Key %d not found in the binary search tree.\n", searchKey);
    }

    // Deleting a node
    printf("Deleting key %d from the binary search tree.\n", 20);
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory (simple cleanup)
    while (root) {
        root = deleteNode(root, root->key);
    }

    return 0;
}