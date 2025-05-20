//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the binary search tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
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

// Function to find the minimum value node
Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to visualize the tree
void visualize(Node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }
    space += 5; // Increase distance between levels

    // Process right child first
    visualize(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    visualize(root->left, space);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;
    
    printf("Welcome to the Enchanted Binary Forest!\n");
    printf("1: Insert a number\n");
    printf("2: Delete a number\n");
    printf("3: Visualize the BST\n");
    printf("4: Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d has been added to the forest!\n", value);
                break;

            case 2:
                printf("Enter a number to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d has been removed from the forest!\n", value);
                break;

            case 3:
                printf("Visualizing the Binary Search Tree:\n");
                visualize(root, 0);
                break;

            case 4:
                printf("Thank you for visiting the Enchanted Binary Forest!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}