//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Insert a new node with the given data into the binary search tree
struct Node* insert(struct Node *root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // If the data is less than the root's data, insert it into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // If the data is greater than the root's data, insert it into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the root of the tree
    return root;
}

// Search for a node with the given data in the binary search tree
struct Node* search(struct Node *root, int data) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is equal to the root's data, return the root
    if (data == root->data) {
        return root;
    }

    // If the data is less than the root's data, search for it in the left subtree
    else if (data < root->data) {
        return search(root->left, data);
    }

    // If the data is greater than the root's data, search for it in the right subtree
    else {
        return search(root->right, data);
    }
}

// Print the binary search tree in preorder traversal
void preorder(struct Node *root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }

    // Print the root's data
    printf("%d ", root->data);

    // Print the left subtree
    preorder(root->left);

    // Print the right subtree
    preorder(root->right);
}

// Print the binary search tree in inorder traversal
void inorder(struct Node *root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }

    // Print the left subtree
    inorder(root->left);

    // Print the root's data
    printf("%d ", root->data);

    // Print the right subtree
    inorder(root->right);
}

// Print the binary search tree in postorder traversal
void postorder(struct Node *root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }

    // Print the left subtree
    postorder(root->left);

    // Print the right subtree
    postorder(root->right);

    // Print the root's data
    printf("%d ", root->data);
}

// Free the binary search tree
void free_tree(struct Node *root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }

    // Free the left subtree
    free_tree(root->left);

    // Free the right subtree
    free_tree(root->right);

    // Free the root
    free(root);
}

// Main function
int main() {
    // Create a binary search tree
    struct Node *root = NULL;

    // Insert some data into the binary search tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Search for a node with the given data in the binary search tree
    struct Node *node = search(root, 15);

    // Print the node's data if it was found
    if (node != NULL) {
        printf("Node with data %d found\n", node->data);
    } else {
        printf("Node with data 15 not found\n");
    }

    // Free the binary search tree
    free_tree(root);

    return 0;
}