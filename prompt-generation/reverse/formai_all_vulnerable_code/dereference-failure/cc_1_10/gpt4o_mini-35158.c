//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
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

// Function to search for a node in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    return data < root->data ? search(root->left, data) : search(root->right, data);
}

// Function for in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function for pre-order traversal of the BST
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function for post-order traversal of the BST
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to print the BST in a structured manner
void printTree(struct Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space); // Print right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data); // Print the current node

    printTree(root->left, space); // Print left child
}

// Menu function to dip into the tree operations
void menu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert Node\n");
    printf("2. Search Node\n");
    printf("3. In-order Traversal\n");
    printf("4. Pre-order Traversal\n");
    printf("5. Post-order Traversal\n");
    printf("6. Print Tree Structure\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

// Main program
int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter number to search: ");
                scanf("%d", &data);
                struct Node* foundNode = search(root, data);
                if (foundNode) {
                    printf("Node %d found in the tree.\n", data);
                } else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Tree Structure:\n");
                printTree(root, 0);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}