//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// define a node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// function to insert a new node
Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// function to search for a node
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// function to print the tree in order
void print_in_order(Node* root) {
    if (root == NULL) {
        return;
    }
    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
}

// example main function
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 17);
    printf("The tree in order: ");
    print_in_order(root);
    printf("\n");
    Node* result = search(root, 13);
    if (result == NULL) {
        printf("13 is not in the tree.\n");
    }
    else {
        printf("13 is in the tree.\n");
    }
    return 0;
}