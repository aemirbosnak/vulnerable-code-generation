//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node in the BST
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

// Function for in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to visualize the tree
void printTree(Node* root, int space) {
    int COUNT = 10; // Define the space between nodes
    if (root == NULL) {
        return;
    }
    space += COUNT;
    printTree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

// Function to search for a value in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Main function to drive the program
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Visualization ---\n");
        printf("1. Insert a Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Visualize Tree\n");
        printf("4. Search for a Node\n");
        printf("5. Exit\n");
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
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Visualizing Tree:\n");
                printTree(root, 0);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found) {
                    printf("Found: %d\n", found->data);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}