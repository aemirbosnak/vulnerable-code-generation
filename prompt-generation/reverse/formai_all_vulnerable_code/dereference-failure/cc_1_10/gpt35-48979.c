//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in a binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// A recursive function to create a binary tree from an array
Node* createTree(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = arr[mid];
    root->left = createTree(arr, start, mid-1);
    root->right = createTree(arr, mid+1, end);

    return root;
}

// A recursive function to print a binary tree in-order traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a binary tree from the array
    Node* root = createTree(arr, 0, n-1);

    // Print the binary tree in-order traversal
    printf("In-order traversal of the binary tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}