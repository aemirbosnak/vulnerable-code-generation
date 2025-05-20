//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to insert a new node with the given key in the BST
void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = (struct Node*)malloc(sizeof(struct Node));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a node with the given key in the BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == key) {
        return 1;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the elements of the BST in inorder traversal
void inorder(struct Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert elements in the BST
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Search for elements in the BST
    printf("Searching for 50: %d\n", search(root, 50));
    printf("Searching for 30: %d\n", search(root, 30));
    printf("Searching for 70: %d\n", search(root, 70));

    // Print the elements of the BST in inorder traversal
    printf("\nInorder traversal of the BST:\n");
    inorder(root);

    return 0;
}