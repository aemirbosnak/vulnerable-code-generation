//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the tree inorder
void printInorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int choice, data;

    // Create an empty tree
    struct node* root = NULL;

    // Loop until the user chooses to exit
    while (true) {
        printf("1. Insert\n2. Search\n3. Print inorder\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);

            struct node* result = search(root, data);

            if (result == NULL) {
                printf("Data not found\n");
            } else {
                printf("Data found\n");
            }
            break;

        case 3:
            printf("Inorder traversal:\n");
            printInorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}