//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct node {
    int key;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given key
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new key into the tree
void insert(struct node* root, int key) {
    // If the root is NULL, create a new node
    if (root == NULL) {
        root = newNode(key);
    }
    // Otherwise, traverse the tree to find the correct position to insert the key
    else {
        struct node* current = root;
        while (1) {
            if (key < current->key) {
                if (current->left == NULL) {
                    current->left = newNode(key);
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else if (key > current->key) {
                if (current->right == NULL) {
                    current->right = newNode(key);
                    break;
                }
                else {
                    current = current->right;
                }
            }
            else {
                break;
            }
        }
    }
}

// Function to search for a key in the tree
int search(struct node* root, int key) {
    // If the root is NULL, the key was not found
    if (root == NULL) {
        return -1;
    }
    // Otherwise, traverse the tree to find the key
    else {
        struct node* current = root;
        while (1) {
            if (key < current->key) {
                if (current->left == NULL) {
                    return -1;
                }
                else {
                    current = current->left;
                }
            }
            else if (key > current->key) {
                if (current->right == NULL) {
                    return -1;
                }
                else {
                    current = current->right;
                }
            }
            else {
                return 1;
            }
        }
    }
}

// Function to print the elements of the tree inorder
void printInorder(struct node* root) {
    if (root!= NULL) {
        printInorder(root->left);
        printf("%d ", root->key);
        printInorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    printf("Inorder traversal of the tree: ");
    printInorder(root);
    printf("\n");
    printf("Search for key 40: %d\n", search(root, 40));
    printf("Search for key 90: %d\n", search(root, 90));
    printf("Search for key 100: %d\n", search(root, 100));
    return 0;
}