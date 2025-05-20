//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary search tree node
typedef struct BST_node{
    int value;
    struct BST_node* left;
    struct BST_node* right;
} BST_Node;

// Function to create a new node
BST_Node* create_node(int value){
    BST_Node* newNode = (BST_Node*)malloc(sizeof(BST_Node));
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

// Function to insert node into the BST
BST_Node* insert(BST_Node* root, int value){
    if (root == NULL){
        root = create_node(value);
        return root;
    }
    else{
        if (value <= root -> value){
            root -> left = insert(root -> left, value);
        }
        else{
            root -> right = insert(root -> right, value);
        }
    }
    return root;
}

// Function to print all nodes of the BST in inorder traversal, left->root->right
void inorder_traversal(BST_Node* root){
    if (root != NULL){
        inorder_traversal(root -> left);
        printf("%d ", root -> value);
        inorder_traversal(root -> right);
    }
}

// Function to search for a node in the BST
BST_Node* search(BST_Node* root, int value){
    if (root == NULL || root -> value == value){
        return root;
    }
    else if (value <= root -> value){
        return search(root -> left, value);
    }
    else{
        return search(root -> right, value);
    }
}

// Main function to demonstrate BST operations
int main(){
    BST_Node* root = NULL;
    root = insert(root, 10);           
    insert(root, 20);
    insert(root, 5);
    insert(root, 3);
    insert(root, 9);
    insert(root, 25);
    insert(root, 14);
    insert(root, 30);
  
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    int search_value = 9;
    BST_Node* node_found = search(root, search_value);
    if (node_found != NULL){
        printf("Node with Value %d is FOUND in the BST!\n", search_value);
    }
    else{
        printf("Node with Value %d is NOT FOUND in the BST!\n", search_value);
    }

    return 0;
}