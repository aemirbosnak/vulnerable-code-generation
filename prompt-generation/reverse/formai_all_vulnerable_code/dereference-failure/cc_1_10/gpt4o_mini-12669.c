//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
void visualizeTree(struct Node* root, int space);
void freeTree(struct Node* root);

// Added space between the levels of the tree for visualization
#define COUNT 10

int main() {
    struct Node* root = NULL;
    int value;
    char choice;

    printf("Binary Search Tree Visualization\n");
    do {
        printf("\nEnter a value to insert into the BST: ");
        scanf("%d", &value);
        root = insertNode(root, value);
        
        printf("\nCurrent Tree Visualization:\n");
        visualizeTree(root, 0);
        
        printf("Do you want to insert another value? (y/n): ");
        getchar(); // To consume the newline character
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    freeTree(root);
    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Visualize the BST in a structured manner
void visualizeTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += COUNT; // Increase distance between levels

    visualizeTree(root->right, space); // Process right subtree first

    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data); // Print the current node
    
    visualizeTree(root->left, space); // Process left subtree
}

// Free the allocated memory for the tree
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}