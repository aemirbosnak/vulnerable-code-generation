//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data and return a pointer to it
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary tree rooted at the given node
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Find the minimum value in the binary tree rooted at the given node
int find_min(struct node *root) {
    if (root == NULL) {
        return -1; // Return -1 if the tree is empty
    } else if (root->left == NULL) {
        return root->data; // Return the data of the root if it has no left child
    } else {
        return find_min(root->left); // Recursively find the minimum value in the left subtree
    }
}

// Find the maximum value in the binary tree rooted at the given node
int find_max(struct node *root) {
    if (root == NULL) {
        return -1; // Return -1 if the tree is empty
    } else if (root->right == NULL) {
        return root->data; // Return the data of the root if it has no right child
    } else {
        return find_max(root->right); // Recursively find the maximum value in the right subtree
    }
}

// Print the binary tree rooted at the given node in preorder traversal
void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data); // Print the data of the root
        print_preorder(root->left); // Recursively print the left subtree
        print_preorder(root->right); // Recursively print the right subtree
    }
}

// Print the binary tree rooted at the given node in inorder traversal
void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        print_inorder(root->left); // Recursively print the left subtree
        printf("%d ", root->data); // Print the data of the root
        print_inorder(root->right); // Recursively print the right subtree
    }
}

// Print the binary tree rooted at the given node in postorder traversal
void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        print_postorder(root->left); // Recursively print the left subtree
        print_postorder(root->right); // Recursively print the right subtree
        printf("%d ", root->data); // Print the data of the root
    }
}

// Free the memory allocated for the binary tree rooted at the given node
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        free_tree(root->left); // Recursively free the left subtree
        free_tree(root->right); // Recursively free the right subtree
        free(root); // Free the root node
    }
}

// Main function
int main() {
    // Create the root node of the binary tree
    struct node *root = create_node(10);

    // Insert some values into the binary tree
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    print_postorder(root);
    printf("\n");

    // Find the minimum value in the binary tree
    printf("Minimum value: %d\n", find_min(root));

    // Find the maximum value in the binary tree
    printf("Maximum value: %d\n", find_max(root));

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}