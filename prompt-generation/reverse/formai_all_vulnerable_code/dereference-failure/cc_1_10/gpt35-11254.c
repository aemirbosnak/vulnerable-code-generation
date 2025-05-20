//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Defining the binary search tree node
struct bst_node{
    int value;
    struct bst_node* left_child;
    struct bst_node* right_child;
};

// Function to insert a new node in the BST
struct bst_node* insert_node(struct bst_node* node, int value){
    // If the tree is empty, create a new node and return it
    if(node == NULL){
        node = (struct bst_node*)malloc(sizeof(struct bst_node));
        node->value = value;
        node->left_child = NULL;
        node->right_child = NULL;
        return node;
    }
    // If the value is less than the root node, insert it in the left subtree
    if(value < node->value){
        node->left_child = insert_node(node->left_child, value);
    }
    // If the value is greater than the root node, insert it in the right subtree
    else if(value > node->value){
        node->right_child = insert_node(node->right_child, value);
    }
    // Return the unchanged node pointer
    return node;
}

// Function to search for a node in the BST
struct bst_node* search_node(struct bst_node* node, int value){
    // If the tree is empty or the value is found at the root node, return the node
    if(node == NULL || node->value == value){
        return node;
    }
    // If the value is greater than the root node, search in the right subtree
    if(value > node->value){
        return search_node(node->right_child, value);
    }
    // If the value is less than the root node, search in the left subtree
    else{
        return search_node(node->left_child, value);
    }
}

// Function to traverse the BST in order
void inorder_traversal(struct bst_node* node){
    if(node != NULL){
        inorder_traversal(node->left_child);
        printf("%d ", node->value);
        inorder_traversal(node->right_child);
    }
}

// Function to delete a node from the BST
struct bst_node* delete_node(struct bst_node* node, int value){
    // If the tree is empty, return NULL
    if(node == NULL){
        return node;
    }
    // If the value is less than the node value, search in the left subtree
    if(value < node->value){
        node->left_child = delete_node(node->left_child, value);
    }
    // If the value is greater than the node value, search in the right subtree
    else if(value > node->value){
        node->right_child = delete_node(node->right_child, value);
    }
    // If the value is equal to the node value, delete the node
    else{
        // If the node has only one child or no child, replace it with its child
        if(node->left_child == NULL){
            struct bst_node* temp = node->right_child;
            free(node);
            return temp;
        }
        else if(node->right_child == NULL){
            struct bst_node* temp = node->left_child;
            free(node);
            return temp;
        }
        // If the node has two children, find the inorder successor (smallest value in the right subtree)
        struct bst_node* temp = node->right_child;
        while(temp->left_child != NULL){
            temp = temp->left_child;
        }
        // Replace the node value with the inorder successor value
        node->value = temp->value;
        // Delete the inorder successor
        node->right_child = delete_node(node->right_child, temp->value);
    }
    // Return the unchanged node pointer
    return node;
}

// Main function
int main(){
    struct bst_node* root = NULL;
    printf("Binary Search Tree Example Program\n");
    // Insert nodes in the BST
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);
    // Traverse the BST in order
    printf("Inorder Traversal of BST: ");
    inorder_traversal(root);
    printf("\n");
    // Search for a node in the BST
    struct bst_node* search_result = search_node(root, 60);
    if(search_result != NULL){
        printf("Node found: %d\n", search_result->value);
    }
    else{
        printf("Node not found.\n");
    }
    // Delete a node from the BST
    root = delete_node(root, 40);
    // Traverse the BST in order
    printf("Inorder Traversal of BST: ");
    inorder_traversal(root);
    printf("\n");
    // Exit the program
    return 0;
}