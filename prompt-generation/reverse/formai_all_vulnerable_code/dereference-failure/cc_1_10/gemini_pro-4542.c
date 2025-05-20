//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Custom data structure to store a node in a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Recursive function to insert a new node into a binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node and return it
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (data < root->data) {
        // If the data is less than the root's data, insert it into the left subtree
        root->left = insert(root->left, data);
    } else {
        // If the data is greater than or equal to the root's data, insert it into the right subtree
        root->right = insert(root->right, data);
    }

    // Return the root of the modified tree
    return root;
}

// Recursive function to search for a node with a given data value in a binary tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    } else if (data == root->data) {
        // If the data matches the root's data, return the root
        return root;
    } else if (data < root->data) {
        // If the data is less than the root's data, search the left subtree
        return search(root->left, data);
    } else {
        // If the data is greater than the root's data, search the right subtree
        return search(root->right, data);
    }
}

// Recursive function to find the minimum value in a binary tree
struct Node* find_min(struct Node* root) {
    if (root == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    } else if (root->left == NULL) {
        // If the left child is NULL, the root is the minimum value
        return root;
    } else {
        // Recursively find the minimum value in the left subtree
        return find_min(root->left);
    }
}

// Recursive function to find the maximum value in a binary tree
struct Node* find_max(struct Node* root) {
    if (root == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    } else if (root->right == NULL) {
        // If the right child is NULL, the root is the maximum value
        return root;
    } else {
        // Recursively find the maximum value in the right subtree
        return find_max(root->right);
    }
}

// Recursive function to delete a node with a given data value from a binary tree
struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    } else if (data == root->data) {
        // If the data matches the root's data, delete the root
        if (root->left == NULL && root->right == NULL) {
            // If the root has no children, simply delete it
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // If the root has no left child, replace it with its right child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // If the root has no right child, replace it with its left child
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // If the root has both children, replace it with its successor
            struct Node* successor = find_min(root->right);
            root->data = successor->data;
            root->right = delete(root->right, successor->data);
            return root;
        }
    } else if (data < root->data) {
        // If the data is less than the root's data, delete it from the left subtree
        root->left = delete(root->left, data);
    } else {
        // If the data is greater than the root's data, delete it from the right subtree
        root->right = delete(root->right, data);
    }

    // Return the root of the modified tree
    return root;
}

// Recursive function to print a binary tree in preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive function to print a binary tree in inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Recursive function to print a binary tree in postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create a binary tree
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Search for a node with data value 7
    struct Node* found = search(root, 7);
    if (found != NULL) {
        printf("Node with data value 7 found!\n");
    } else {
        printf("Node with data value 7 not found!\n");
    }

    // Find the minimum value in the tree
    struct Node* min = find_min(root);
    if (min != NULL) {
        printf("Minimum value in the tree: %d\n", min->data);
    }

    // Find the maximum value in the tree
    struct Node* max = find_max(root);
    if (max != NULL) {
        printf("Maximum value in the tree: %d\n", max->data);
    }

    // Delete the node with data value 15
    root = delete(root, 15);

    // Print the tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Print the tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}