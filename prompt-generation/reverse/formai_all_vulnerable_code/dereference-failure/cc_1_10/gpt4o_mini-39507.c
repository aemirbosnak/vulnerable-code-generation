//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

// Function to search for a value in the binary search tree
struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return searchNode(root->left, value);
    return searchNode(root->right, value);
}

// Function to find the minimum value in a binary search tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with one child or no child
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
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the tree in-order (sorted order)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the tree memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Function to display menu and prompt for user input
void displayMenu() {
    printf("Binary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. In-Order Traversal\n");
    printf("5. Exit\n");
}

// Main function to drive the program
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Value %d inserted into the tree.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = searchNode(root, value);
                if (foundNode != NULL)
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted from the tree.\n", value);
                break;

            case 4:
                printf("In-Order Traversal of the Tree: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program. Freeing up resources...\n");
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}