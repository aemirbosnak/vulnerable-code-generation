//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        root = newNode(value);
        return root;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Function to print the BST in order traversal
void printOrder(struct Node* root) {
    if (root == NULL)
        return;

    printOrder(root->left);
    printf("%d ", root->data);
    printOrder(root->right);
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the BST in post-order traversal
void printPostOrder(struct Node* root) {
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Driver code
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Order traversal: ");
    printOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    return 0;
}