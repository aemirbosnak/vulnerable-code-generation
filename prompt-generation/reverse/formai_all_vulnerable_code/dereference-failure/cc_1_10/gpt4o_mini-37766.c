//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with given key into BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(key);
    }
    // Otherwise, recur down the tree
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    // Return the unchanged node pointer
    return root;
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    // Key is greater than root's key
    if (key > root->data) {
        return search(root->right, key);
    }
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to print the inorder traversal of a binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in the binary search tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with given key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base Case
    if (root == NULL) {
        return root;
    }
    // If the key to be deleted is smaller than the root's key, it lies in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    // If the key to be deleted is greater than the root's key, it lies in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
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
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate binary search tree operations
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into BST.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted from BST if it existed.\n", value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* searchResult = search(root, value);
                if (searchResult != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }
    return 0;
}