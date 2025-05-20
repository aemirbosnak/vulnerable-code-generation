//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
struct node {
    char data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(char data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the BST
void insert(struct node* root, char data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (data < root->data)
        insert(root->left, data);
    else if (data > root->data)
        insert(root->right, data);
}

// Function to search for a node with the given data in the BST
struct node* search(struct node* root, char data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

// Function to print the BST in order traversal
void printOrder(struct node* root) {
    if (root == NULL)
        return;

    printOrder(root->left);
    printf("%c ", root->data);
    printOrder(root->right);
}

// Function to print the BST in preorder traversal
void printPreOrder(struct node* root) {
    if (root == NULL)
        return;

    printf("%c ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the BST in postorder traversal
void printPostOrder(struct node* root) {
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%c ", root->data);
}

// Driver code
int main() {
    struct node* root = NULL;

    // Inserting nodes
    insert(root, 'A');
    insert(root, 'B');
    insert(root, 'C');
    insert(root, 'D');
    insert(root, 'E');

    // Printing BST in order traversal
    printf("Order traversal: ");
    printOrder(root);
    printf("\n");

    // Printing BST in preorder traversal
    printf("Preorder traversal: ");
    printPreOrder(root);
    printf("\n");

    // Printing BST in postorder traversal
    printf("Postorder traversal: ");
    printPostOrder(root);
    printf("\n");

    return 0;
}