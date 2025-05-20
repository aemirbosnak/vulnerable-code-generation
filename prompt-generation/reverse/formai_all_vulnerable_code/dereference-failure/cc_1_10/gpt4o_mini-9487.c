//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the nodes of the binary search tree
typedef struct Node {
    int key;
    char value[50];
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int key, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
Node* insert(Node* root, int key, const char* value) {
    if (root == NULL) {
        return createNode(key, value);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    }  // Duplicate keys are not allowed

    return root;
}

// Function to search for a node with a specific key
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum key in the binary search tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        strcpy(root->value, temp->value);
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to print the binary search tree in-order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d: %s\n", root->key, root->value);
        inOrder(root->right);
    }
}

// Main function to demonstrate the binary search tree functions
int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50, "Root Node");
    root = insert(root, 30, "Left Child");
    root = insert(root, 70, "Right Child");
    root = insert(root, 20, "Left Grandchild");
    root = insert(root, 40, "Left Right Child");
    root = insert(root, 60, "Right Left Child");
    root = insert(root, 80, "Right Grandchild");

    // Output the tree
    printf("In-order traversal of the binary search tree:\n");
    inOrder(root);
    
    // Searching for a specific key
    int keyToSearch = 40;
    Node* searchResult = search(root, keyToSearch);
    if (searchResult) {
        printf("Found node with key %d: %s\n", searchResult->key, searchResult->value);
    } else {
        printf("Node with key %d not found.\n", keyToSearch);
    }

    // Deleting a node
    printf("Deleting node with key 30...\n");
    root = deleteNode(root, 30);
    
    // Output the tree after deletion
    printf("In-order traversal after deletion:\n");
    inOrder(root);

    // Freeing the allocated memory would typically be done here (not shown for brevity)

    return 0;
}