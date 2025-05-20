//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Binary Search Tree
typedef struct Node {
    int data;
    struct Node* left_child;
    struct Node* right_child;
} Node;

// Create a new node with the given data
Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

// Insert the given data into the Binary Search Tree
Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left_child = insert_node(root->left_child, data);
    } else if (data > root->data) {
        root->right_child = insert_node(root->right_child, data);
    }

    return root;
}

// Search for the given data in the Binary Search Tree
Node* search_node(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_node(root->left_child, data);
    } else {
        return search_node(root->right_child, data);
    }
}

// Print the in-order traversal of the Binary Search Tree
void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left_child);
        printf("%d ", root->data);
        inorder_traversal(root->right_child);
    }
}

int main() {
    printf("Welcome to the Binary Search Tree Program!\n");

    Node* root = NULL;

    printf("\nLet's add some values to our tree...\n");
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 8);
    root = insert_node(root, 3);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    printf("\nThe values in our tree are: ");
    inorder_traversal(root);

    printf("\n\nLet's search for the value 12 in our tree...\n");
    Node* node = search_node(root, 12);
    if (node != NULL) {
        printf("The value 12 was found in the tree!\n");
    } else {
        printf("The value 12 was not found in the tree.\n");
    }

    printf("\nLet's search for the value 6 in our tree...\n");
    node = search_node(root, 6);
    if (node != NULL) {
        printf("The value 6 was found in the tree!\n");
    } else {
        printf("The value 6 was not found in the tree.\n");
    }

    printf("\nThank you for using the Binary Search Tree Program!\n");

    return 0;
}