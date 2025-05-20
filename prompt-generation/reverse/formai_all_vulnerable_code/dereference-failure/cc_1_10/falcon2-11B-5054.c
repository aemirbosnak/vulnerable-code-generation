//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Binary Search Tree Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
void insert(struct Node* node, int data) {
    if (node == NULL) {
        node = createNode(data);
    } else if (data < node->data) {
        insert(node->left, data);
    } else if (data > node->data) {
        insert(node->right, data);
    }
}

// Function to search for a given data in the binary search tree
int search(struct Node* node, int data) {
    if (node == NULL) {
        return -1;
    }
    if (data < node->data) {
        return search(node->left, data);
    } else if (data > node->data) {
        return search(node->right, data);
    } else {
        return node->data;
    }
}

// Function to print the elements of the binary search tree in inorder traversal
void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main() {
    struct Node* root = NULL;

    for (int i = 1; i <= MAX_SIZE; i++) {
        insert(root, i);
    }

    printf("Inorder Traversal of Binary Search Tree:\n");
    inorderTraversal(root);

    int data;
    printf("Enter a data to search: ");
    scanf("%d", &data);

    int result = search(root, data);
    if (result == -1) {
        printf("Data not found in the Binary Search Tree\n");
    } else {
        printf("Data found at index %d\n", result);
    }

    return 0;
}