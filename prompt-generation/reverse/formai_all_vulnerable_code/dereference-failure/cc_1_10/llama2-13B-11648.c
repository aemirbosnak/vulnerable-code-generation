//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node** root_ref, int data) {
    struct Node* current = *root_ref;
    struct Node* new_node = newNode(data);

    if (*root_ref == NULL) {
        *root_ref = new_node;
        return new_node;
    }

    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                break;
            }
            current = current->left;
        } else if (data > current->data) {
            if (current->right == NULL) {
                current->right = new_node;
                break;
            }
            current = current->right;
        } else {
            // Data already present in the tree, do nothing
            return current;
        }
    }

    return new_node;
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    struct Node* current = root;

    while (current != NULL) {
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }

    return NULL;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node** root_ref, int data) {
    struct Node* current = *root_ref;

    if (*root_ref == NULL) {
        return NULL;
    }

    if (data < current->data) {
        current->left = deleteNode(current->left, data);
    } else if (data > current->data) {
        current->right = deleteNode(current->right, data);
    } else {
        // Found the node to be deleted, replace it with its left or right child
        if (current->left == NULL) {
            current->right = NULL;
        } else if (current->right == NULL) {
            current->left = NULL;
        } else {
            // Find the inorder successor of the node to be deleted
            struct Node* successor = current->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            // Replace the node to be deleted with its inorder successor
            successor->left = current->left;
            current->left = NULL;
        }
    }

    return current;
}

// Function to print the binary search tree
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes into the binary search tree
    root = insertNode(&root, 5);
    root = insertNode(&root, 2);
    root = insertNode(&root, 8);
    root = insertNode(&root, 3);
    root = insertNode(&root, 1);
    root = insertNode(&root, 6);

    // Search for a node in the binary search tree
    struct Node* search_result = searchNode(root, 3);
    printf("Node found at %p\n", search_result);

    // Delete a node from the binary search tree
    struct Node* delete_result = deleteNode(&root, 5);
    printf("Deleted node at %p\n", delete_result);

    // Print the binary search tree
    printTree(root);

    return 0;
}