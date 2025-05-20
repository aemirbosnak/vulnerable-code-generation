//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with a given value
Node* create_node(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a value into the binary search tree
Node* insert_value(Node* root, int val) {
    if (root == NULL) {
        root = create_node(val);
        return root;
    }

    if (val < root->data) {
        root->left = insert_value(root->left, val);
    } else if (val > root->data) {
        root->right = insert_value(root->right, val);
    }

    return root;
}

// Function to print the binary search tree in-order
void print_inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Function to search a value in the binary search tree
Node* search_value(Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }

    if (val < root->data) {
        return search_value(root->left, val);
    } else {
        return search_value(root->right, val);
    }
}

int main() {
    Node* root = NULL;

    // Insert values into the binary search tree
    root = insert_value(root, 10);
    root = insert_value(root, 20);
    root = insert_value(root, 30);
    root = insert_value(root, 40);
    root = insert_value(root, 50);

    // Print the binary search tree in-order
    printf("In-order traversal of the binary search tree:\n");
    print_inorder(root);
    printf("\n");

    // Search for a value in the binary search tree
    Node* search_result = search_value(root, 20);
    if (search_result!= NULL) {
        printf("Value 20 found in the binary search tree.\n");
    } else {
        printf("Value 20 not found in the binary search tree.\n");
    }

    return 0;
}