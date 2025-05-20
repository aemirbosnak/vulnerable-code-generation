//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the Binary Search Tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the Binary Search Tree
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to find the minimum value node in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a value from the Binary Search Tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the tree in inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver code to demonstrate Binary Search Tree operations
int main() {
    struct Node* root = NULL;
    int values[] = {15, 10, 20, 8, 12, 17, 25};
    int i;

    // Insert elements into the Binary Search Tree
    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal of the given tree:\n");
    inorder(root);
    printf("\n");

    // Search for a value in the tree
    int searchValue = 10;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Found node with value %d\n", searchValue);
    } else {
        printf("Node with value %d not found\n", searchValue);
    }

    // Delete a value from the tree
    int deleteValue = 10;
    root = deleteNode(root, deleteValue);
    printf("Inorder traversal after deleting %d:\n", deleteValue);
    inorder(root);
    printf("\n");

    // Free remaining nodes
    root = deleteNode(root, 15);
    root = deleteNode(root, 20);
    root = deleteNode(root, 8);
    root = deleteNode(root, 12);
    root = deleteNode(root, 17);
    root = deleteNode(root, 25);

    return 0;
}