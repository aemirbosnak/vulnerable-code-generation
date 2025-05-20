//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // If the data to be inserted is less than the root's data,
    // then it lies in left subtree
    if (data < root->data)
        root->left = insert(root->left, data);
    // If the data to be inserted is greater than the root's data,
    // then it lies in right subtree
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged root pointer
    return root;
}

// Function to search for a value in BST
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data);

    return search(root->left, data);
}

// Function to print inorder traversal of BST
void printInorder(struct node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert data into BST
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    // Print inorder traversal of BST
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");

    // Search for a value in BST
    struct node* searchResult = search(root, 10);
    if (searchResult!= NULL)
        printf("Value %d found in BST\n", searchResult->data);
    else
        printf("Value %d not found in BST\n", 5);

    return 0;
}