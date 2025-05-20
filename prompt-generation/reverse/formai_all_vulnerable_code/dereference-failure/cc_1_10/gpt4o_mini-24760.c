//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value in the BST
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

// Function to print the tree in a visual way
void printTree(Node* root, int space) {
    int COUNT = 10; // Difference between levels
    if (root == NULL) return;

    space += COUNT;

    printTree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, value;

    printf("Binary Search Tree Visualization Program\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert value\n");
        printf("2. Visualize tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
            case 2:
                printf("Current binary search tree:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Exiting program.\n");
                free(root); // Clean up memory before exiting
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}