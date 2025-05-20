//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a binary search tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with the given key
struct Node* insert(struct Node* node, int key) {
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

// Function to do inorder traversal of the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to search a given key in the tree
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) 
        return root;
    
    // Key is greater than root's key
    if (root->key < key) 
        return search(root->right, key);
        
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum value node in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with a given key
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL) return root;

    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
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
        
        // Node with two children: Get the inorder successor (smallest 
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;  // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
    }
    return root;
}

// Function to free the allocated memory for the BST
void freeTree(struct Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main function to demonstrate the binary search tree operations
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* searchResult = search(root, value);
                if (searchResult != NULL)
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}