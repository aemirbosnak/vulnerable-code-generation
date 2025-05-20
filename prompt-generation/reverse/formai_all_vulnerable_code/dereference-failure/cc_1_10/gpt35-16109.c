//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a new node in the Binary Search Tree
struct Node* addNode(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = addNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = addNode(node->right, data);
    }

    return node;
}

// Function to search for a node in the Binary Search Tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value in a tree rooted at the given node
struct Node* findMin(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the Binary Search Tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
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

// Function to print the Binary Search Tree in Inorder Traversal
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Add some nodes to the Binary Search Tree
    root = addNode(root, 50);
    addNode(root, 30);
    addNode(root, 20);
    addNode(root, 40);
    addNode(root, 70);
    addNode(root, 60);
    addNode(root, 80);

    // Print the Binary Search Tree in Inorder Traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node in the Binary Search Tree
    struct Node* node = searchNode(root, 40);
    printf("Searched node: %d\n", node->data);

    // Delete a node from the Binary Search Tree
    root = deleteNode(root, 30);
    printf("After deletion, Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}