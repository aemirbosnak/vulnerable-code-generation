//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a value in BST
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        return newNode(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function to search for a value in BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Function to print the tree in order
void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

// Function to visualize the tree structure
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10; // Increase distance between levels

    // Process right child first
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Visualization Menu:\n");
        printf("1. Insert a number\n");
        printf("2. Search for a number\n");
        printf("3. Print tree in order\n");
        printf("4. Visualize tree structure\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;
            case 2:
                printf("Enter a number to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("In-order traversal of the tree: ");
                printInOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Visualizing tree structure:\n");
                printTree(root, 0);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}