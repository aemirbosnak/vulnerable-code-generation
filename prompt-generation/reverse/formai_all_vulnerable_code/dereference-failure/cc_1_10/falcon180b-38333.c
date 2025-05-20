//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Otherwise, traverse down the tree to find the correct position
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root node
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the BST in order traversal
void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the BST in post-order traversal
void printPostOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;

    // Insert some values into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);

    // Print the BST in order traversal
    printf("In-order traversal: ");
    printInOrder(root);
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
    struct Node* node = search(root, 7);
    if (node!= NULL) {
        printf("Found value %d in the BST\n", node->data);
    } else {
        printf("Value %d not found in the BST\n", 7);
    }

    // Free the memory used by the BST
    free(root);

    return 0;
}