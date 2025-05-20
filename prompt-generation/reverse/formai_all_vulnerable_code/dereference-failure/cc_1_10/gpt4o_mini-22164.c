//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Search Tree (BST) node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key into the BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
    
    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    
    // Return the unchanged node pointer
    return node;
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) return root;

    // Key is greater than root's key
    if (root->key < key) return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum value node in a given BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case
    if (root == NULL) return root;

    // Recursive calls for ancestors of the key to be deleted
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        // Place the inorder successor's key in this node
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to do inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to free the BST nodes
void freeTree(struct Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Main function to demonstrate the operations on BST
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    int key = 40;
    struct Node* found = search(root, key);
    if (found != NULL) {
        printf("Found %d in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    printf("Deleting 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    printf("Deleting 50...\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    // Clean up memory
    freeTree(root);
    
    return 0;
}