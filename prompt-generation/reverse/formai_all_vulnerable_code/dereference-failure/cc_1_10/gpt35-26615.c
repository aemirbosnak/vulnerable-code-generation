//FormAI DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the tree
void insert_node(Node **root_ptr, int value) {
    if (*root_ptr == NULL) {
        *root_ptr = create_node(value);
    }
    else if (value < (*root_ptr)->value) {
        insert_node(&((*root_ptr)->left), value);
    }
    else {
        insert_node(&((*root_ptr)->right), value);
    }
}

// Function to search for a node in the tree
Node* search_node(Node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    else if (value < root->value) {
        return search_node(root->left, value);
    }
    else {
        return search_node(root->right, value);
    }
}

// Function to delete a node from the tree
Node* delete_node(Node *root, int value) {
    if (root == NULL) {
        return root;
    }
    else if (value < root->value) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}

// Function to traverse the tree in-order
void inorder_traversal(Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

// Main function to demonstrate the binary search tree
int main() {
    Node *root = NULL;
    insert_node(&root, 4);
    insert_node(&root, 2);
    insert_node(&root, 6);
    insert_node(&root, 1);
    insert_node(&root, 3);
    insert_node(&root, 5);
    insert_node(&root, 7);
    printf("Binary Search Tree:");
    inorder_traversal(root);
    root = delete_node(root, 4);
    printf("\nBinary Search Tree after deleting 4:");
    inorder_traversal(root);
    return 0;
}