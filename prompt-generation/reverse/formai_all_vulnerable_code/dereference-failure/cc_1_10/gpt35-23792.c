//FormAI DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Node
struct Node {
    int data; // data of the node
    struct Node* left; // left pointer of the node
    struct Node* right; // right pointer of the node
};

// Function to create a new node
struct Node* createNewNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    // If root is null, create a new node and return it
    if (root == NULL) {
        return createNewNode(data);
    }
    // If data is less than the root node's data, insert into the left subtree
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than or equal to the root node's data, insert into the right subtree
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to print the Binary Search Tree in Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate the visualization of Binary Search Tree
int main() {
    printf("Visualization of Binary Search Tree\n\n");
    
    // Creating Binary Search Tree
    struct Node* root = insert(NULL, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Visualizing Binary Search Tree
    printf("            %d\n", root->data);
    printf("           / \\\n");
    printf("         %d   %d\n", root->left->data, root->right->data);
    printf("        / \\   / \\\n");
    printf("      %d  %d %d   %d\n", root->left->left->data, root->left->right->data, root->right->left->data, root->right->right->data);

    // Printing Binary Search Tree using Inorder traversal
    printf("\nInorder traversal of Binary Search Tree: ");
    inorderTraversal(root);

    // Freeing allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);
    return 0;
}