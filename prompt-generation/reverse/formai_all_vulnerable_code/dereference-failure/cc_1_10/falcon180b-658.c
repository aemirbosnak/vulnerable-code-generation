//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for our binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Oops! Memory could not be allocated.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to print out the values in the BST in order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to print out the values in the BST in reverse order
void printReverseOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printReverseOrder(root->right);
    printf("%d ", root->data);
    printReverseOrder(root->left);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert some values into the tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print out the values in order
    printf("In order traversal:\n");
    printInOrder(root);
    printf("\n");

    // Print out the values in reverse order
    printf("Reverse order traversal:\n");
    printReverseOrder(root);
    printf("\n");

    return 0;
}