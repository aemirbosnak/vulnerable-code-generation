//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary search tree node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Helper function for creating a new node
Node *newNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// Insert a new node into the tree
Node *insert(Node *node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node -> data) {
        node -> left = insert(node -> left, data);
    } else if (data > node -> data) {
        node -> right = insert(node -> right, data);
    }

    return node;
}

// Search the tree for a given key
Node *search(Node *root, int key) {
    if (root == NULL || root -> data == key) {
        return root;
    }

    if (root -> data < key) {
        return search(root -> right, key);
    }

    return search(root -> left, key);
}

// Inorder traversal of the tree
void inorder(Node *node) {
    if (node != NULL) {
        inorder(node -> left);
        printf("%d ", node -> data);
        inorder(node -> right);
    }
}

// Main function for testing the program
int main() {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree: ");
    inorder(root);

    int key = 40;
    if (search(root, key) != NULL) {
        printf("\n%d is present in the binary search tree", key);
    } else {
        printf("\n%d is not present in the binary search tree", key);
    }

    return 0;
}