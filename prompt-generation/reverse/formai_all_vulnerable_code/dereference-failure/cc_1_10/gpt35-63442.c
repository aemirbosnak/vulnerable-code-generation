//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new Node in the tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a Node in the tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == data) {
        return root;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Traverse the tree in-order
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    struct Node* root = NULL; // Initialize the tree

    // Insert nodes into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 17);

    // Search for a Node in the tree
    struct Node* searchedNode = search(root, 7);
    if (searchedNode != NULL) {
        printf("Found the node with value %d in the tree!\n", searchedNode->data);
    }
    else {
        printf("The node with value 7 does not exist in the tree.\n");
    }

    // Traverse the tree in-order
    printf("In-order traversal of the tree: ");
    inOrder(root);

    return 0;
}