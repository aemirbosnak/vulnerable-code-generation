//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool searchNode(Node *root, int data) {
    if (root == NULL) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree:\n");
        printf("1. Insert a new value\n");
        printf("2. Search for a value\n");
        printf("3. Traverse the tree (In-Order)\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                if (searchNode(root, value)) {
                    printf("Value found!\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 3:
                printf("Traversing the tree (In-Order): ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    free(root);

    return 0;
}