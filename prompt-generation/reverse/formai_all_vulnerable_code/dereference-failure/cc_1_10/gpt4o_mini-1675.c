//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a value in the tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // This node must be deleted
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the binary search tree operations
int main() {
    struct Node* root = NULL;

    // Surprise! Let's add some random values to our tree.
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        printf("Inserting %d into the tree...\n", values[i]);
        root = insert(root, values[i]);
    }

    // Surprise! Let’s print the inorder traversal of the tree
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    // Searching for a value in the tree
    int searchValue = 40;
    struct Node* foundNode = search(root, searchValue);
    if (foundNode != NULL) {
        printf("Value %d found in the tree!\n", foundNode->data);
    } else {
        printf("Oops! Value %d not found in the tree.\n", searchValue);
    }

    // Deleting a node from the tree
    int deleteValue = 30;
    printf("Deleting node with value %d...\n", deleteValue);
    root = deleteNode(root, deleteValue);
    
    // Print inorder traversal after deletion
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory (a surprise cleanup for our tree!)
    while (root != NULL) {
        root = deleteNode(root, root->data);  // Delete all nodes
    }

    return 0;
}