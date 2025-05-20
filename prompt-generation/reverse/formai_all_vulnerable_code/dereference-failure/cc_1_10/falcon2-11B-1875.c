//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to insert a new node in BST
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

// Function to print the BST inorder
void printInorder(struct node* node) {
    if (node!= NULL) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

// Function to search a value in BST
int search(struct node* node, int data) {
    if (node == NULL || node->data == data)
        return 1;
    else if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

// Driver program to test above functions
int main() {
    struct node* root = NULL;

    // Inserting values in BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Printing the BST inorder
    printf("Inorder traversal of BST:\n");
    printInorder(root);

    // Searching a value in BST
    int data;
    printf("\nSearch for 30: %d", search(root, 30));
    printf("\nSearch for 75: %d", search(root, 75));

    return 0;
}