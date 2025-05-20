//FormAI DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new empty node
struct node *newNode(int data) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Insert a new node into the binary search tree
struct node *insert(struct node *node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return (node);
}

// Print the nodes of the binary search tree in inorder traversal
void inorderTraversal(struct node *node) {
    if (node == NULL) return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Search for a node with a given data value in the binary search tree
struct node *search(struct node *node, int data) {
    if (node == NULL || node->data == data) return node;

    if (node->data < data)
        return search(node->right, data);

    return search(node->left, data);
}

// Main function to demonstrate the use of the binary search tree
int main() {

    struct node *root = NULL;

    // Insert some nodes into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the nodes of the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node with a given data value in the binary search tree
    struct node *searchResult = search(root, 40);
    if (searchResult != NULL) {
        printf("Element found: %d\n", searchResult->data);
    } else {
        printf("Element not found\n");
    }

    return 0;
}