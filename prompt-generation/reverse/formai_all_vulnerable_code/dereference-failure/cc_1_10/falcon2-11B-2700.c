//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to insert a new node into the binary search tree
void insert(struct node** root, int data) {
    // If the root is NULL, create a new node and make it the root
    if (*root == NULL) {
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    // Otherwise, traverse the tree until we find an empty spot to insert the new node
    else {
        struct node* current = *root;
        while (current!= NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    struct node* newNode = (struct node*)malloc(sizeof(struct node));
                    newNode->data = data;
                    newNode->left = NULL;
                    newNode->right = NULL;
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            else if (data > current->data) {
                if (current->right == NULL) {
                    struct node* newNode = (struct node*)malloc(sizeof(struct node));
                    newNode->data = data;
                    newNode->left = NULL;
                    newNode->right = NULL;
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
            else {
                printf("Data already exists in the tree\n");
                break;
            }
        }
    }
}

// Function to search for a node in the binary search tree
int search(struct node* root, int data) {
    struct node* current = root;
    while (current!= NULL) {
        if (data < current->data) {
            current = current->left;
        }
        else if (data > current->data) {
            current = current->right;
        }
        else {
            return 1; // Data found in the tree
        }
    }
    return 0; // Data not found in the tree
}

// Function to print the elements of the binary search tree in inorder traversal
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Create a new binary search tree
    struct node* root = NULL;

    // Insert some nodes into the binary search tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);

    // Print the elements of the binary search tree in inorder traversal
    inorder(root);

    // Search for a node in the binary search tree
    int data = 40;
    if (search(root, data)) {
        printf("Node found with value %d\n", data);
    }
    else {
        printf("Node not found\n");
    }

    return 0;
}