//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with the given data
Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary search tree
Node *insert_node(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Traverse the binary search tree in pre-order fashion and print out the data
void pre_order_traversal(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

// Traverse the binary search tree in in-order fashion and print out the data
void in_order_traversal(Node *root) {
    if (root == NULL) {
        return;
    }

    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

// Traverse the binary search tree in post-order fashion and print out the data
void post_order_traversal(Node *root) {
    if (root == NULL) {
        return;
    }

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create a new binary search tree with the root node having data 10
    Node *root = create_node(10);

    // Insert additional nodes with data 5, 15, 3, and 7
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
    root = insert_node(root, 7);

    // Print out the data in pre-order fashion
    printf("Pre-order traversal:\n");
    pre_order_traversal(root);
    printf("\n");

    // Print out the data in in-order fashion
    printf("In-order traversal:\n");
    in_order_traversal(root);
    printf("\n");

    // Print out the data in post-order fashion
    printf("Post-order traversal:\n");
    post_order_traversal(root);
    printf("\n");

    return 0;
}