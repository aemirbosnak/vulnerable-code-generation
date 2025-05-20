//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
void insert(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

// Function to search for a node
int search(struct node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the BST
void print_bst(struct node* root) {
    if (root == NULL) {
        return;
    }
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

int main() {
    struct node* root = NULL;

    // Insert elements in the BST
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    // Search for a node
    if (search(root, 50)) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }

    // Print the BST
    printf("Pre-order traversal of the BST:\n");
    print_bst(root);

    return 0;
}