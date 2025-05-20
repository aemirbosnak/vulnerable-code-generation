//FormAI DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert into the tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search a node
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data);

    return search(root->left, data);
}

// Function to traverse the tree in inorder
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to traverse the tree in preorder
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to traverse the tree in postorder
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Driver function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Search for a node
    int searchValue = 40;
    struct Node* searchedNode = search(root, searchValue);
    if (searchedNode != NULL) {
        printf("%d is found in the BST!\n", searchValue);
    } else {
        printf("%d is not found in the BST!\n", searchValue);
    }

    return 0;
}