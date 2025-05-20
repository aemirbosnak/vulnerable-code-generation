//FormAI DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Binary Search Tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value
int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    } else if (root->data == value) {
        return 1;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to find minimum value in BST
int findMin(Node* root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return findMin(root->left);
    }
}

// Function to find maximum value in BST
int findMax(Node* root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return findMax(root->right);
    }
}

// Function to count the number of nodes in BST
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        return leftNodes + rightNodes + 1;
    }
}

// Print all the elements of the tree in order
void traverseInOrder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        traverseInOrder(root->left);
        printf("%d ", root->data);
        traverseInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value, result;

    while (1) {
        printf("\n\nBinary Search Tree\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Count Nodes\n");
        printf("6. Traverse In Order\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result == 1) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;

            case 3:
                printf("The minimum value is: %d\n", findMin(root));
                break;

            case 4:
                printf("The maximum value is: %d\n", findMax(root));
                break;

            case 5:
                printf("The number of nodes in the tree is: %d\n", countNodes(root));
                break;

            case 6:
                printf("The elements of the tree in order are: ");
                traverseInOrder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}