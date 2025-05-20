//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int key;
    struct node* left;
    struct node* right;
};

// Function to insert a node in the BST
void insert(struct node** root, int key) {
    if (*root == NULL) {
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (key < (*root)->key) {
            insert(&((*root)->left), key);
        } else {
            insert(&((*root)->right), key);
        }
    }
}

// Function to search a node in the BST
int search(struct node* root, int key) {
    if (root == NULL) {
        return 0;
    } else if (root->key == key) {
        return 1;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the nodes in inorder traversal
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to print the nodes in preorder traversal
void preorder(struct node* root) {
    if (root!= NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to print the nodes in postorder traversal
void postorder(struct node* root) {
    if (root!= NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    // Creating a BST
    struct node* root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);
    insert(&root, 80);
    insert(&root, 90);
    insert(&root, 100);

    // Printing the BST
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of the BST: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of the BST: ");
    postorder(root);
    printf("\n");

    // Searching for a key
    int key = 80;
    int found = search(root, key);
    if (found == 1) {
        printf("Key %d found in the BST\n", key);
    } else {
        printf("Key %d not found in the BST\n", key);
    }

    return 0;
}