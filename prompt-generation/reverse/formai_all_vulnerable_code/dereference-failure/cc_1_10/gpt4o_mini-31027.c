//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary search tree node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int item) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key in the BST
Node* insert(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the unchanged node pointer
    return node;
}

// Function to perform inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to search a given key in BST
Node* search(Node* root, int key) {
    // Base case: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum value node in a given BST
Node* minValueNode(Node* node) {
    Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with a given key from the BST
Node* deleteNode(Node* root, int key) {
    // Base Case: If the tree is empty
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, go to the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than the root's key, go to the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    // If key is the same as root's key, this is the node to be deleted
    else {
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
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function to demonstrate Binary Search Tree operations
int main() {
    Node* root = NULL;

    // Insert some random values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree: \n");
    inorder(root);
    printf("\n");

    int key = 40;
    Node* result = search(root, key);
    if (result != NULL)
        printf("Found: %d\n", result->key);
    else
        printf("Key %d not found in the tree.\n", key);

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion of 20:\n");
    inorder(root);
    printf("\n");

    printf("Delete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion of 30:\n");
    inorder(root);
    printf("\n");

    printf("Delete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion of 50:\n");
    inorder(root);
    printf("\n");

    return 0;
}