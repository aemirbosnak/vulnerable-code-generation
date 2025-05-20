//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Function to insert a node into the binary tree
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

// Function to calculate the height of the tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to print the tree structure
void printTree(Node* root, int space) {
    const int COUNT = 10;
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

// Main function
int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("Binary Tree Visualization\n");
        printf("1. Insert node\n");
        printf("2. Visualize tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Binary Tree Visualization:\n");
                int h = height(root);
                if(h == 0){
                    printf("Tree is empty.\n");
                }else{
                    printTree(root, 0);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}