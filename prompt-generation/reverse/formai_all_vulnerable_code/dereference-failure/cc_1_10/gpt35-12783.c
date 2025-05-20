//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; // holds the data
    struct node* left; // pointer to left child
    struct node* right; // pointer to right child
};

// create function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // allocate space for new node
    new_node->data = data; // set data
    new_node->left = NULL; // set left child to NULL
    new_node->right = NULL; // set right child to NULL
    return new_node; // return new node
}

// insert function to insert a new node into the tree
struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data); // create new node if root is null
    } else if (data < root->data) {
        root->left = insert_node(root->left, data); // insert into left subtree
    } else {
        root->right = insert_node(root->right, data); // insert into right subtree
    }
    return root;
}

// search function to search for a node in the tree
struct node* search_node(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data); // search in left subtree
    } else {
        return search_node(root->right, data); // search in right subtree
    }
}

// inorder traversal function to print out the tree in order
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left); // traverse left subtree
        printf("%d ", root->data); // print data
        inorder_traversal(root->right); // traverse right subtree
    }
}

int main() {
    struct node* root = NULL; // initialize root to NULL

    // insert nodes into tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    printf("Inorder traversal of binary search tree: ");
    inorder_traversal(root); // print out the tree in order
    
    // search for nodes in tree
    printf("\nSearching for node with value of 40...\n");
    struct node* node_40 = search_node(root, 40);
    if (node_40 != NULL) {
        printf("Node with value of 40 has been found!\n");
    } else {
        printf("Node with value of 40 was not found...\n");
    }

    printf("\nSearching for node with value of 100...\n");
    struct node* node_100 = search_node(root, 100);
    if (node_100 != NULL) {
        printf("Node with value of 100 has been found!\n");
    } else {
        printf("Node with value of 100 was not found...\n");
    }

    return 0;
}