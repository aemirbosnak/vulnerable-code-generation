//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Node of Binary Search Tree
typedef struct node {
    int data;
    struct node *left, *right;
} node;

// Insert a node into the Binary Search Tree
node *insert_node(node *root, int data) {
    if (root == NULL) {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Search a node in the Binary Search Tree
node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    } else {
        return root;
    }
}

// Delete a node from the Binary Search Tree
node *delete_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            // Find the inorder successor of the node to be deleted
            node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            // Copy the data of inorder successor to the node to be deleted
            root->data = temp->data;
            // Delete the inorder successor
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Print the Binary Search Tree in inorder
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    // Create a Binary Search Tree
    node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Search a node in the Binary Search Tree
    node *found_node = search_node(root, 40);
    if (found_node != NULL) {
        printf("Node %d found in the Binary Search Tree.\n", found_node->data);
    } else {
        printf("Node not found in the Binary Search Tree.\n");
    }

    // Delete a node from the Binary Search Tree
    root = delete_node(root, 20);
    printf("Binary Search Tree after deleting node 20:\n");
    inorder(root);
    printf("\n");

    return 0;
}