//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define a struct for binary tree nodes
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the binary tree
struct node *insert(struct node *root, int data) {
    // If root is NULL, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    // Return the updated root pointer
    return root;
}

// Search for a node with the given data in the binary tree
struct node *search(struct node *root, int data) {
    // Base Cases: root is NULL or data is present at root
    if (root == NULL || root->data == data) {
        return root;
    }
  
    // data is greater than root's data, recur right subtree
    if (root->data < data) {
        return search(root->right, data);
    }
  
    // data is smaller than root's data, recur left subtree
    return search(root->left, data);
}

// Print the nodes of the binary tree in inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
  
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int choice = 0;
    int data = 0;

    printf("Welcome to the post-apocalyptic search program.\n"
           "Please enter the number of nodes you want to insert into the binary tree:\n");
    scanf("%d", &choice);

    for(int i = 0; i < choice; i++) {
        printf("Enter the data for node %d:\n", i+1);
        scanf("%d", &data);
        root = insert(root, data);
    }
  
    printf("Inorder traversal of the binary tree is: ");
    inorder(root);
    printf("\n");

    printf("Please enter the data you want to search for:\n");
    scanf("%d", &data);

    struct node *searchResult = search(root, data);

    if(searchResult != NULL) {
        printf("The data %d was found in the binary tree.\n", data);
    } else {
        printf("The data %d was not found in the binary tree.\n", data);
    }

    return 0;
}