//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert the data into the binary search tree
void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Check if the data is present in the binary search tree
int search(struct Node* root, int data) {
    if (root == NULL) {
        return -1;
    }
    
    if (data == root->data) {
        return 1;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print the binary search tree in in-order traversal
void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program to test the above functions
int main() {
    struct Node* root = NULL;
    
    root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Binary Search Tree:\n");
    inorder(root);
    printf("\n");
    
    int searchData = 40;
    int result = search(root, searchData);
    
    if (result == 1) {
        printf("%d is present in the binary search tree.\n", searchData);
    } else {
        printf("%d is not present in the binary search tree.\n", searchData);
    }
    
    return 0;
}