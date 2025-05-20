//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key in BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

// Function to do inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inoder traversal of the BST
    printf("Inorder traversal of the binary search tree:\n");
    inorder(root);

    // Search for a key
    int key = 60;
    while(root != NULL){
        if(root->key == key){
            printf("Key %d is found in the BST.\n", key);
            break;
        }
        else if (root->key < key){
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    if(root == NULL)
    printf("Key %d is not found in the BST.\n", key);

    // Success!
    return 0;
}