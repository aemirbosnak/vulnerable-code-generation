//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserts a new node in the BST
struct Node* insert(struct Node* root, int data) {
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
        struct Node* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the tree in a visual format
void printTree(struct Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

// Function to free the tree
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to demonstrate BST operations
int main() {
    struct Node* root = NULL;
    char choice;
    int value;

    printf("Binary Search Tree Visualization\n");
    printf("Options:\n");
    printf("I: Insert a node\n");
    printf("D: Delete a node\n");
    printf("P: Print the tree\n");
    printf("Q: Quit\n");

    do {
        printf("Enter your choice (I/D/P/Q): ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'I':
            case 'i':
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 'D':
            case 'd':
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 'P':
            case 'p':
                printf("Current Tree Structure:\n");
                printTree(root, 0);
                break;
            case 'Q':
            case 'q':
                printf("Exiting the program...\n");
                freeTree(root);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}