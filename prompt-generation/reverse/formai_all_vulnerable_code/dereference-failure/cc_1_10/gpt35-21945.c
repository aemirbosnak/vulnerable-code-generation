//FormAI DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the BST
struct node *search(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Function to traverse the BST in-order
void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Driver code
int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");
    
    int n;
    printf("Enter a number to search in the BST: ");
    scanf("%d", &n);
    
    struct node *result = search(root, n);
    if (result == NULL) {
        printf("Node not found in the BST\n");
    }
    else {
        printf("Node found in the BST\n");
    }
    
    return 0;
}