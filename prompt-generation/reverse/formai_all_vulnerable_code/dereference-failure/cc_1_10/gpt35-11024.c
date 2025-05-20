//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

// Function to insert nodes in the binary search tree
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root -> data)
        root -> left = insert(root -> left, value);

    if (value > root -> data)
        root -> right = insert(root -> right, value);

    return root;
}

// Function to print the tree using inorder traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root -> left);
        printf("%d ", root -> data);
        inorderTraversal(root -> right);
    }
}

int main() {

    Node* root = NULL;

    // Inserting data into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Printing the tree
    printf("\n\n\t\t Binary Search Tree Visualization\n");
    printf("\t\t----------------------------------\n\n");
    
    printf("                                                  %d\n", root -> data);
    printf("                    %d                                            %d\n", root -> left -> data, root -> right -> data);
    printf("             %d             %d                               %d             %d\n", root -> left -> left -> data, root -> left -> right -> data, root -> right -> left -> data, root -> right -> right -> data);

    printf("\n\nInorder Traversal of the Binary Search Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}