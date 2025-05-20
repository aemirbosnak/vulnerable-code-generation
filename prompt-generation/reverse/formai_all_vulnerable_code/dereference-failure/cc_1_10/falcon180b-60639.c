//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the struct for the node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the tree
void insert(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

// Function to search for a node in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the tree in-order
void print_in_order(struct node* root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
}

// Function to print the tree pre-order
void print_pre_order(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    print_in_order(root->left);
    print_in_order(root->right);
}

// Function to print the tree post-order
void print_post_order(struct node* root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    print_in_order(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert nodes into the tree
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Print the tree in-order
    printf("In-order traversal: ");
    print_in_order(root);
    printf("\n");

    // Print the tree pre-order
    printf("Pre-order traversal: ");
    print_pre_order(root);
    printf("\n");

    // Print the tree post-order
    printf("Post-order traversal: ");
    print_post_order(root);
    printf("\n");

    // Search for a node in the tree
    struct node* search_node = search(root, 6);
    if (search_node!= NULL) {
        printf("Node found with data %d\n", search_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}