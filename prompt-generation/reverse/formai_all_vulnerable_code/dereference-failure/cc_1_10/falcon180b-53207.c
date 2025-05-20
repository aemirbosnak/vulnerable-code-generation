//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// In-order traversal of the binary search tree
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Search for a node with the given data in the binary search tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Delete a node with the given data from the binary search tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = root->right;
            while (temp->left!= NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Main function to test the binary search tree operations
int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    printf("In-order traversal of the binary search tree:\n");
    inOrderTraversal(root);

    printf("\nSearching for node with data 40:\n");
    Node* searchResult = searchNode(root, 40);
    if (searchResult!= NULL) {
        printf("Node found with data %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    printf("\nDeleting node with data 20:\n");
    root = deleteNode(root, 20);
    inOrderTraversal(root);

    return 0;
}