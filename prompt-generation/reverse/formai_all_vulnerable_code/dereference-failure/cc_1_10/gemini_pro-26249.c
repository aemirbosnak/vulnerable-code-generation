//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A utility function to create a new Binary Tree node
struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a new node with the given key into the given Binary Search Tree
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// A utility function to find the inorder successor of a given node in BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// A utility function to delete a given key from BST
struct Node* deleteNode(struct Node* node, int key) {
    // base case
    if (node == NULL) return NULL;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < node->data)
        node->left = deleteNode(node->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > node->data)
        node->right = deleteNode(node->right, key);

    // If the key to be deleted is the same as the root's key, then this is the node to be deleted
    else {
        // node with only one child or no child
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// A utility function to print the inorder traversal of the BST
void inorder(struct Node* node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Driver program to test the above functions
int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given BST:\n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified BST:\n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified BST:\n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified BST:\n");
    inorder(root);

    return 0;
}