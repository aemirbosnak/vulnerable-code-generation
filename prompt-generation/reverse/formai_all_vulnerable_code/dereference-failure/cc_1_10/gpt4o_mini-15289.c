//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Search Tree Node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to insert a new node with the given key
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
    
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    // Return the (unchanged) node pointer
    return node;
}

// Utility function to do inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at the root
    if (root == NULL || root->key == key)
        return root;
    
    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum value node in the given subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with the given key
struct Node* deleteNode(struct Node* root, int key) {
    // Base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    
    // If key is same as root's key, then this is the node to be deleted
    else {
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

        // Node with two children:
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function to demonstrate the operations on the BST
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the inorder traversal of the BST
    printf("Inorder traversal of the given tree: ");
    inorder(root);
    printf("\n");

    // Search for a key
    int searchKey = 40;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL)
        printf("Key %d found in the tree.\n", searchKey);
    else
        printf("Key %d not found in the tree.\n", searchKey);

    // Delete a key
    printf("Deleting key 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting key 20: ");
    inorder(root);
    printf("\n");

    // Delete a key
    printf("Deleting key 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting key 30: ");
    inorder(root);
    printf("\n");

    // Delete a key
    printf("Deleting key 50...\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deleting key 50: ");
    inorder(root);
    printf("\n");

    return 0;
}