//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define a node struct
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

// Function to insert a node in a Binary Search Tree
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a node in a Binary Search Tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data);

    return search(root->left, data);
}

// Function to traverse a Binary Search Tree in-order
void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL; // Initialize the root of the Binary Search Tree

    // Insert some nodes in the BST
    root = insert(root, 16);
    root = insert(root, 8);
    root = insert(root, 24);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 28);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 18);
    root = insert(root, 22);
    root = insert(root, 26);
    root = insert(root, 30);

    printf("Nodes inserted successfully in the Binary Search Tree!\n");

    printf("In-order traversal of the Binary Search Tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a node in the BST
    int searchData = 14;
    Node* searchedNode = search(root, searchData);

    if (searchedNode == NULL)
        printf("Node %d not found in the Binary Search Tree.\n", searchData);
    else
        printf("Node %d found in the Binary Search Tree!\n", searchedNode->data);

    // Free the memory occupied by the Binary Search Tree
    free(root);

    return 0;
}