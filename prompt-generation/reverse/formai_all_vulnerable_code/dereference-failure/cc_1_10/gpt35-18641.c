//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include<stdlib.h>
#include<stdio.h>

typedef struct node { // Binary search tree node structure
    int val;
    struct node *left;
    struct node *right;
} node;

node* new_node(int val) { // Function to create a new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, int val) { // Function to insert a node in the BST
    if(root == NULL) {
        root = new_node(val);
        return root;
    } else if(val <= root->val) {
        root->left = insert_node(root->left, val);
    } else {
        root->right = insert_node(root->right, val);
    }
    return root;
}

void inorder_traversal(node* root) { // Function for inorder traversal of the BST
    if(root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->val);
        inorder_traversal(root->right);
    }
}

int search_tree(node* root, int val) { // Function to search for a value in the BST
    if(root == NULL) {
        return 0;
    } else if(root->val == val) {
        return 1;
    } else if(val <= root->val) {
        return search_tree(root->left, val);
    } else {
        return search_tree(root->right, val);
    }
}

int main() {
    node* root = NULL;
    int arr[] = {5, 7, 2, 9, 1, 4, 6, 8, 3}; // Sample input array
    int n = sizeof(arr)/sizeof(int); // Calculating the number of nodes to be inserted in the BST
    int i;

    for(i=0; i<n; i++) { // Inserting nodes in the BST
        root = insert_node(root, arr[i]);
    }

    printf("Inorder Traversal of the BST: ");
    inorder_traversal(root);
    printf("\n");

    if(search_tree(root, 8)) { // Searching for a value in the BST
        printf("8 is present in the BST\n");
    } else {
        printf("8 is not present in the BST\n");
    }

    if(search_tree(root, 10)) { // Searching for a value in the BST
        printf("10 is present in the BST\n");
    } else {
        printf("10 is not present in the BST\n");
    }

    return 0; // Program ends here
}