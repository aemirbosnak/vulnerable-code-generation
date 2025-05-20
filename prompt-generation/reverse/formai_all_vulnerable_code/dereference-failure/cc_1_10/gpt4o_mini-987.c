//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in the binary search tree
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node in the binary search tree
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Function to search a given key in the binary search tree
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) return root;

    // Key is greater than root's key
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to perform inorder traversal of the binary search tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to free the allocated memory of the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary search tree
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Printing in-order traversal of the BST
    printf("In-order traversal of the binary search tree: ");
    inorder(root);
    printf("\n");

    // Searching for a value
    int searchKey = 40;
    if (search(root, searchKey) != NULL) {
        printf("Key %d found in the tree.\n", searchKey);
    } else {
        printf("Key %d not found in the tree.\n", searchKey);
    }

    // Freeing allocated memory for the tree
    freeTree(root);
    
    return 0;
}