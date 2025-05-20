//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// structure to represent a node in the Binary Search Tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} NODE;

// function to create a new node with the given data value
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a new node with the given data value into the Binary Search Tree
NODE* insertNode(NODE* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// function to search for a given data value in the Binary Search Tree
NODE* searchNode(NODE* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data <= root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// function to find the minimum value node in the Binary Search Tree
NODE* findMinNode(NODE* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// function to delete a node with the given data value from the Binary Search Tree
NODE* deleteNode(NODE* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: one child
        else if (root->left == NULL) {
            NODE* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            NODE* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: two children
        else {
            NODE* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// inorder traversal of the Binary Search Tree
void inorderTraversal(NODE* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    NODE* root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Search nodes
    NODE* searchResult = NULL;
    searchResult = searchNode(root, 40);
    if (searchResult != NULL) {
        printf("Found node: %d\n", searchResult->data);
    }
    else {
        printf("Node not found.");
    }

    // Delete nodes
    root = deleteNode(root, 20);
    root = deleteNode(root, 40);
    root = deleteNode(root, 70);

    // Inorder traversal of nodes
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}