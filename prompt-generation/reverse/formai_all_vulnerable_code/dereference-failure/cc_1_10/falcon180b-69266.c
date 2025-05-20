//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, create a new node as root
    if (root == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to search for a value in the BST
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to perform an inorder traversal of the BST
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform a preorder traversal of the BST
void preorder(struct node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform a postorder traversal of the BST
void postorder(struct node* root) {
    if (root!= NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert some values into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traverse the tree in different orders
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Search for a value in the tree
    struct node* found = search(root, 40);
    if (found!= NULL) {
        printf("Found %d in the tree\n", found->data);
    } else {
        printf("Could not find %d in the tree\n", 40);
    }

    return 0;
}