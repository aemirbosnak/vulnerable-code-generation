//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create new node
Node *createNode(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Insert node into BST
Node *insertNode(Node *node, int data) {
    // If tree is empty, create new node
    if (node == NULL) {
        return createNode(data);
    }

    // If data is smaller than node's data, go left
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    }
    // If data is greater than node's data, go right
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

// Search for node in BST given a key
Node *search(Node *node, int key) {
    // If tree is empty or node is the root
    if (node == NULL || node->data == key) {
        return node;
    }

    // If key is smaller than node's data, go left
    if (key < node->data) {
        return search(node->left, key);
    }
    // If key is greater than node's data, go right
    else {
        return search(node->right, key);
    }
}

int main() {
    // Welcome to the Cyberpunk Binary Search Tree
    printf("Welcome to the Cyberpunk Binary Search Tree!\n");
    printf("In this world, data is power and you are the master of the code.\n");

    // Initialize the root node
    Node *root = NULL;
    int choice, data, key;
    char ch;

    do {
        // Menu options
        printf("\nMenu:\n");
        printf("1. Insert Data\n");
        printf("2. Search Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Insert data into BST
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("%d has been inserted into the Tree.\n", data);
                break;
            case 2:
                // Search for data in BST
                printf("Enter data to be searched: ");
                scanf("%d", &key);
                Node *result = search(root, key);
                if (result == NULL) {
                    printf("Data not found in the Tree.\n");
                }
                else {
                    printf("%d has been found in the Tree.\n", result->data);
                }
                break;
            case 3:
                // Exit program
                printf("Exiting Cyberpunk Binary Search Tree...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Prompt user to continue
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y');

    return 0;
}