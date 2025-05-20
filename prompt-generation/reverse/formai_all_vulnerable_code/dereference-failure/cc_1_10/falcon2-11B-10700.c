//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node definition
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to insert a new node with given key
void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = (struct Node*)malloc(sizeof(struct Node));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else if (key > (*root)->key) {
        insert(&(*root)->right, key);
    }
}

// Function to search a node with given key
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }
}

// Function to print the binary tree in inorder traversal
void inorder(struct Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    int key;

    // Insert nodes
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Search nodes
    printf("Inorder traversal of the binary tree: \n");
    inorder(root);

    printf("Search key 30: %s\n", search(root, 30)? "Found" : "Not Found");
    printf("Search key 50: %s\n", search(root, 50)? "Found" : "Not Found");
    printf("Search key 70: %s\n", search(root, 70)? "Found" : "Not Found");
    printf("Search key 100: %s\n", search(root, 100)? "Found" : "Not Found");

    return 0;
}