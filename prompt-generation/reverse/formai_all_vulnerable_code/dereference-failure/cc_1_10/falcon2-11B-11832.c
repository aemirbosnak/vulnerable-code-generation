//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Structure to hold node
struct node {
    int key;
    struct node *left, *right;
};

// Function to insert a new key in BST
struct node* insert(struct node* root, int key) {
    if (root == NULL)
        return (struct node*)malloc(sizeof(struct node));

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to print BST
void printBST(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->key);
    printBST(root->left);
    printBST(root->right);
}

int main() {
    struct node* root = NULL;

    // Insert some keys in BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 22);
    root = insert(root, 16);
    root = insert(root, 6);

    // Print BST
    printf("BST is: \n");
    printBST(root);

    return 0;
}