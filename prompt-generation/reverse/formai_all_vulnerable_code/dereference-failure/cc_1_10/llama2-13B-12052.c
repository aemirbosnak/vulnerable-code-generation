//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform binary search
int binarySearch(Node* root, int key) {
    int low = 0;
    int high = 100;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (root->data == mid) {
            printf("Found element %d\n", mid);
            return mid;
        }

        if (root->data < mid) {
            high = mid - 1;
            root = root->right;
        } else {
            low = mid + 1;
            root = root->left;
        }
    }

    return -1; // not found
}

// Main function
int main() {
    Node* root = NULL;

    // Create some nodes
    root = newNode(10);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(25);

    // Perform binary search
    int key = 18;
    int result = binarySearch(root, key);

    if (result != -1) {
        printf("Found element %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}