//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
struct node* search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to print the BST in order traversal
void printOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printOrder(root->left);
    printf("%d ", root->data);
    printOrder(root->right);
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the BST in post-order traversal
void printPostOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the BST in order traversal
    printf("Order traversal: ");
    printOrder(root);
    printf("\n");

    // Print the BST in pre-order traversal
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the BST in post-order traversal
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    // Search for a value in the BST
    struct node* searchResult = search(root, 40);
    if (searchResult!= NULL) {
        printf("Value found!\n");
    } else {
        printf("Value not found.\n");
    }

    return 0;
}