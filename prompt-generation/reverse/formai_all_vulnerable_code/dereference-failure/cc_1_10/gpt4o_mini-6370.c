//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

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

// Function to insert data into the binary tree
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

// Function to print the binary tree in a visually appealing way
void printTree(Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space); // Traverse right

    printf("\n");
    for (int i = 10; i < space; i++) printf(" "); // Print spaces
    printf("%d\n", root->data); // Print current node

    printTree(root->left, space); // Traverse left
}

// Function to perform an in-order traversal of the tree
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;

    printf("Welcome to the Binary Tree Visualizer!\n");
    printf("Choose an option:\n");
    printf("1. Insert a node\n");
    printf("2. Display tree\n");
    printf("3. In-Order Traversal\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the tree!\n", value);
                break;
                
            case 2:
                printf("Visualizing the tree:\n");
                printTree(root, 0);
                break;

            case 3:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program. Happy coding!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}