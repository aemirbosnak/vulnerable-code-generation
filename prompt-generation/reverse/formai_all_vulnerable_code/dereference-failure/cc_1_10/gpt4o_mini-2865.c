//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
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

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function for in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to count the number of nodes in the BST
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the height of the BST
int findHeight(Node* root) {
    if (root == NULL) {
        return -1; // Height of empty tree is -1
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// Function to free the memory allocated for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the BST operations
int main() {
    Node* root = NULL;
    int choice, value;
    
    while (1) {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert a Node\n");
        printf("2. Search for a Node\n");
        printf("3. In-order Traversal\n");
        printf("4. Count Nodes\n");
        printf("5. Find Height\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node %d inserted successfully!\n", value);
                break;
                
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("Node %d found in the tree!\n", value);
                } else {
                    printf("Node %d not found in the tree.\n", value);
                }
                break;
                
            case 3:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
                
            case 4:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;
                
            case 5:
                printf("Height of the tree: %d\n", findHeight(root));
                break;
                
            case 6:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}