//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Structure for a Node in the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new Node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to visualize the tree structure
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, level + 1);
    printf("\n");
    for (int i = 0; i < level; i++) {
        printf("       ");
    }
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printf("\n=== Binary Tree Visualization ===");
        printf("\n1. Insert Node");
        printf("\n2. Display Tree");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Inserted %d into the tree!\n", data);
                break;
            case 2:
                printf("\nThe current Binary Tree is:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Exiting... Freeing tree memory.\n");
                freeTree(root);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}