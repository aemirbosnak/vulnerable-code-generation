//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert data into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Search for data in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print tree inorder traversal
void print_inorder(Node* root) {
    if (root!= NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

// Main function
int main() {
    // Create sample tree
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 14);

    // Print tree inorder traversal
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    // Search for data in the tree
    Node* found_node = search(root, 12);
    if (found_node!= NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}