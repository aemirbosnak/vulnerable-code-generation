//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: mind-bending
// A mind-bending Binary Search Trees example

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Insert a node into a binary search tree
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        // Create a new node
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        
        // Return the new node
        return new_node;
    }

    // Recursively insert the node into the left or right subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    // Return the root of the tree
    return root;
}

// Search for a node in a binary search tree
struct node *search(struct node *root, int data) {
    if (root == NULL) {
        // The node is not found
        return NULL;
    }

    // Recursively search for the node in the left or right subtree
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        // The node is found
        return root;
    }
}

// Print a binary search tree in order
void inorder(struct node *root) {
    if (root == NULL) {
        // The tree is empty
        return;
    }

    // Recursively print the left and right subtrees
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Print a binary search tree in preorder
void preorder(struct node *root) {
    if (root == NULL) {
        // The tree is empty
        return;
    }

    // Recursively print the root, left, and right subtrees
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Print a binary search tree in postorder
void postorder(struct node *root) {
    if (root == NULL) {
        // The tree is empty
        return;
    }

    // Recursively print the left, right, and root subtrees
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Find the minimum value in a binary search tree
struct node *find_min(struct node *root) {
    if (root == NULL) {
        // The tree is empty
        return NULL;
    }

    // Recursively find the minimum value in the left subtree
    while (root->left != NULL) {
        root = root->left;
    }

    // Return the minimum value
    return root;
}

// Find the maximum value in a binary search tree
struct node *find_max(struct node *root) {
    if (root == NULL) {
        // The tree is empty
        return NULL;
    }

    // Recursively find the maximum value in the right subtree
    while (root->right != NULL) {
        root = root->right;
    }

    // Return the maximum value
    return root;
}

// Delete a node from a binary search tree
struct node *delete(struct node *root, int data) {
    if (root == NULL) {
        // The node is not found
        return NULL;
    }

    // Recursively delete the node from the left or right subtree
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // The node is found
        if (root->left == NULL) {
            // The node has no left child
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // The node has no right child
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            // The node has two children
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    // Return the root of the tree
    return root;
}

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary search tree in inorder
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    // Print the binary search tree in preorder
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    // Search for a node in the binary search tree
    struct node *found_node = search(root, 12);
    if (found_node != NULL) {
        printf("Found node: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Find the minimum value in the binary search tree
    struct node *min_node = find_min(root);
    printf("Minimum value: %d\n", min_node->data);

    // Find the maximum value in the binary search tree
    struct node *max_node = find_max(root);
    printf("Maximum value: %d\n", max_node->data);

    // Delete a node from the binary search tree
    root = delete(root, 12);

    // Print the binary search tree in inorder
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}