//FormAI DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data) {
    // Creating a new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    // Inserting a node
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node* root, int data) {
    // Searching for a node
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

Node* minValueNode(Node* node) {
    // Finding the min value node
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {
    // Deleting a node
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(Node* root) {
    // Inorder traversal of the tree
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Main function
    Node* root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 9);
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root, 3);
    printf("Inorder traversal after deleting the node: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}