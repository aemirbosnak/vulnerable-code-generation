//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h> 
#include <stdlib.h> 

// node structure for BST
struct node { 
    int key; 
    struct node *left, *right; 
}; 

// function to create a new BST node
struct node *new_node(int item) { 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// function for inorder traversal of BST
void inorder_traversal(struct node *root) { 
    if (root != NULL) { 
        inorder_traversal(root->left); 
        printf("%d \n", root->key); 
        inorder_traversal(root->right); 
    } 
} 

// function to insert a new node in the BST
struct node* insert_node(struct node* node, int key) { 
    if (node == NULL) 
        return new_node(key); 

    if (key < node->key) 
        node->left = insert_node(node->left, key); 
    else if (key > node->key) 
        node->right = insert_node(node->right, key); 

    return node; 
} 

// main function for testing
int main() {
    struct node *root = NULL; 
    root = insert_node(root, 50); 
    insert_node(root, 30); 
    insert_node(root, 20); 
    insert_node(root, 40); 
    insert_node(root, 70); 
    insert_node(root, 60); 
    insert_node(root, 80); 

    printf("Inorder traversal of the BST: \n"); 
    inorder_traversal(root); 

    return 0; 
}