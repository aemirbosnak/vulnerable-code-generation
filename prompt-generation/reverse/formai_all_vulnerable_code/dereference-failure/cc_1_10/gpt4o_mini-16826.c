//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function Prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* node, int data);
bool search(struct Node* root, int data);
void inorderTraversal(struct Node* root);
int minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int data);
void freeTree(struct Node* root);

// Main function demonstrating the Binary Search Tree
int main() {
    struct Node* root = NULL;
    int choice, data;

    // Interactive Menu for Binary Search Tree operations
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the BST.\n", data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("%d is found in the BST.\n", data);
                } else {
                    printf("%d is not found in the BST.\n", data);
                }
                break;
            case 3:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Deleted %d from the BST if it existed.\n", data);
                break;
            case 4:
                printf("Inorder Traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free the allocated memory for the tree
    freeTree(root);
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to search for a given value in the BST
bool search(struct Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    return (data < root->data) ? search(root->left, data) : search(root->right, data);
}

// Function for inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node
int minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        int tempData = minValueNode(root->right);
        root->data = tempData;
        root->right = deleteNode(root->right, tempData);
    }
    return root;
}

// Function to free the allocated memory for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}