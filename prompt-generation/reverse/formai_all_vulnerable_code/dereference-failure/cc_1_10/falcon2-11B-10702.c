//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int key;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the BST
void insert(struct node* node, int key) {
    if (key < node->key) {
        if (node->left == NULL) {
            node->left = create_node(key);
        } else {
            insert(node->left, key);
        }
    } else {
        if (node->right == NULL) {
            node->right = create_node(key);
        } else {
            insert(node->right, key);
        }
    }
}

// Function to find a node in the BST
struct node* find(struct node* node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    } else if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

// Function to print the BST inorder
void inorder(struct node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 70);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST is:\n");
    inorder(root);

    return 0;
}