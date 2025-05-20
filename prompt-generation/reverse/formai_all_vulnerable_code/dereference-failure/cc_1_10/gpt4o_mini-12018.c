//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

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

// Function to insert data into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal to print the tree in a sorted manner
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to visualize the binary tree structure
void visualizeTree(Node* root, int space) {
    int COUNT = 10; // Space count for the visual representation

    if (root == NULL) {
        return;
    }

    space += COUNT;

    visualizeTree(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    visualizeTree(root->left, space);
}

// Function to free the allocated memory for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    // User menu for tree operations
    while (1) {
        printf("\n--- Binary Tree Visualization ---\n");
        printf("1. Insert node\n");
        printf("2. In-order traversal\n");
        printf("3. Visualize tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the tree.\n", value);
                break;

            case 2:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 3:
                printf("Visualizing Tree:\n");
                visualizeTree(root, 0);
                break;

            case 4:
                freeTree(root);
                printf("Exiting...\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}