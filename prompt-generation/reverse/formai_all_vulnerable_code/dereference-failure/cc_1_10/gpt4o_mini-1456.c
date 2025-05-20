//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure definition for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the binary tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to print the tree in-order
void inOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Function to visualize the binary tree structure
void visualizeTree(struct Node* root, int space) {
    const int COUNT = 10;
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

// Main function to run the program
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Tree Visualization\n");
        printf("1. Insert Node\n");
        printf("2. Visualize Tree\n");
        printf("3. In-Order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully.\n", value);
                break;
            case 2:
                printf("Visualizing the tree:\n");
                visualizeTree(root, 0);
                break;
            case 3:
                printf("In-Order Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}