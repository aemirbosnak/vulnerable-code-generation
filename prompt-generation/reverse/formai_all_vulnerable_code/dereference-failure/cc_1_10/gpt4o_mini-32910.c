//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Structure representing a Node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
void inOrderTraversal(struct Node* root);
void preOrderTraversal(struct Node* root);
void postOrderTraversal(struct Node* root);
int height(struct Node* root);
void freeTree(struct Node* root);

// Main function to demonstrate the Binary Search Tree functionalities
int main() {
    struct Node* root = NULL;
    int choice, value;

    // Interactive menu for user input
    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-Order Traversal\n");
        printf("4. Pre-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Height of Tree\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d successfully inserted.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL)
                    printf("Value %d found in the tree.\n", foundNode->data);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;

            case 3:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Post-Order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Height of the tree: %d\n", height(root));
                break;

            case 7:
                freeTree(root);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the BST
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

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// In-Order Traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-Order Traversal of the BST
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-Order Traversal of the BST
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to calculate the height of the BST
int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}