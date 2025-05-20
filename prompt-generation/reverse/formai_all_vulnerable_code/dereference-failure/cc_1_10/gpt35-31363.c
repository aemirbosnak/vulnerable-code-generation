//FormAI DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the binary search tree node
struct bstNode {
    int value;
    struct bstNode* left;
    struct bstNode* right;
};

// Function to create a new binary search tree node with the given value
struct bstNode* newNode(int value) {
    struct bstNode* node = (struct bstNode*)malloc(sizeof(struct bstNode));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a new value into the binary search tree
struct bstNode* insertNode(struct bstNode* node, int value) {
    // If the tree is empty, create a new node and return it
    if (node == NULL) {
        return newNode(value);
    }

    // If the value is smaller than the current node's value, recursively insert into the left subtree
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    }
    // If the value is larger than or equal to the current node's value, recursively insert into the right subtree
    else {
        node->right = insertNode(node->right, value);
    }

    return node;
}

// Function to search for a value in the binary search tree
struct bstNode* searchNode(struct bstNode* node, int value) {
    // If the tree is empty or the value is found at the current node, return the node with the value
    if (node == NULL || node->value == value) {
        return node;
    }

    // If the value is smaller than the current node's value, recursively search the left subtree
    if (value < node->value) {
        return searchNode(node->left, value);
    }
    // If the value is larger than the current node's value, recursively search the right subtree
    else {
        return searchNode(node->right, value);
    }
}

// Function to delete a node with the given value from the binary search tree
struct bstNode* deleteNode(struct bstNode* node, int value) {
    struct bstNode* temp;

    // If the tree is empty, return NULL
    if (node == NULL) {
        return NULL;
    }
    // If the value is smaller than the current node's value, recursively delete from the left subtree
    else if (value < node->value) {
        node->left = deleteNode(node->left, value);
    }
    // If the value is larger than the current node's value, recursively delete from the right subtree
    else if (value > node->value) {
        node->right = deleteNode(node->right, value);
    }
    // If the value is found, delete the node
    else {
        // If the node has no children, simply delete it
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // If the node has one child, replace it with its child
        else if (node->left == NULL) {
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            temp = node->left;
            free(node);
            return temp;
        }
        // If the node has two children, replace it with the smallest value in the right subtree
        else {
            temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
    }

    return node;
}

// Function to print the binary search tree in in-order traversal
void printBST(struct bstNode* node) {
    if (node != NULL) {
        printBST(node->left);
        printf("%d ", node->value);
        printBST(node->right);
    }
}

int main() {
    // Create an example binary search tree
    struct bstNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the binary search tree in in-order traversal
    printf("Binary Search Tree: ");
    printBST(root);
    printf("\n");

    // Search for a value in the binary search tree
    int searchValue = 40;
    struct bstNode* searchResult = searchNode(root, searchValue);
    if (searchResult != NULL) {
        printf("%d found in binary search tree\n", searchValue);
    }
    else {
        printf("%d not found in binary search tree\n", searchValue);
    }

    // Delete a node from the binary search tree
    int deleteValue = 50;
    printf("Deleting node with value %d...\n", deleteValue);
    root = deleteNode(root, deleteValue);

    // Print the binary search tree in in-order traversal after deletion
    printf("Binary Search Tree after deletion: ");
    printBST(root);
    printf("\n");

    return 0;
}