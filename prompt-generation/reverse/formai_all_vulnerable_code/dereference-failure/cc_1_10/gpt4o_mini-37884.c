//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node in a binary tree
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

// Function to visualize the tree
void visualize(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 10;  // Increase distance between levels

    visualize(root->right, space);  // Right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");  // Create space for the current node
    }
    printf("%d\n", root->data);  // Print current node

    visualize(root->left, space);  // Then left child
}

// A tranquil function to traverse the tree in order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Free memory allocated for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// User function to create a binary tree and visualize it
void peacefulTreeVisualization() {
    Node* root = NULL;
    int choice, value;

    printf("Welcome to the Peaceful Binary Tree Visualization\n");
    printf("Choose from the following options:\n");
    printf("1. Insert a value into the tree\n");
    printf("2. Visualize the tree\n");
    printf("3. In-Order Traversal\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted peacefully.\n", value);
                break;
            case 2:
                printf("Visualizing the tree...\n");
                visualize(root, 0);
                break;
            case 3:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                freeTree(root);
                printf("Exiting peacefully. Goodbye!\n");
                exit(0);
            default:
                printf("Please choose a valid option.\n");
        }
    }
}

int main() {
    peacefulTreeVisualization();
    return 0;
}