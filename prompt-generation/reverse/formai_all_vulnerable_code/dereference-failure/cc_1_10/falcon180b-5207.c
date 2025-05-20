//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node with the given data into the binary search tree
void insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Function to search for a node with the given data in the binary search tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum node in the binary search tree
Node* minValueNode(Node* node) {
    while (node->left!= NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with the given data from the binary search tree
Node* deleteNode(Node* root, int data) {
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
        } else if (root->right == NULL) {
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

// Function to print the binary search tree in order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;

    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree\n");
    printInOrder(root);

    printf("\n\n");

    Node* searchNode = search(root, 40);
    if (searchNode!= NULL) {
        printf("Found node with value %d\n", searchNode->data);
    } else {
        printf("Node not found\n");
    }

    printf("\n\n");

    root = deleteNode(root, 20);

    printf("Inorder traversal of the modified tree\n");
    printInOrder(root);

    return 0;
}