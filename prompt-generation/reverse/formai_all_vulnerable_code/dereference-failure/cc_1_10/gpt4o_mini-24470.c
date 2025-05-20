//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary search tree.
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new tree node.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST.
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Distributed function to search for a value in the BST.
int search(Node* root, int key) {
    if (root == NULL) {
        return 0; // Not found
    }
    
    if (root->data == key) {
        return 1; // Found
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Helper function for in-order traversal.
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function that demonstrates distribution of operations.
void distributeOperations() {
    Node* root = NULL;
    int choice, value, found;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display In-Order\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(root, value);
                if (found) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("In-Order Traversal of BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function to execute the program.
int main() {
    printf("Binary Search Tree - Distributed Operations Example\n");
    distributeOperations();
    return 0;
}