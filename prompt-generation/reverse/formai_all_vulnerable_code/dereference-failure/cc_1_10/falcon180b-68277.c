//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the binary search tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the binary search tree in order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to print the binary search tree pre-order
void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the binary search tree post-order
void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;

    // Insert values into the binary search tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    // Print the binary search tree in order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Print the binary search tree pre-order
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the binary search tree post-order
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    // Search for a value in the binary search tree
    Node* searchResult = search(root, 30);
    if (searchResult!= NULL) {
        printf("30 found in the binary search tree.\n");
    } else {
        printf("30 not found in the binary search tree.\n");
    }

    return 0;
}