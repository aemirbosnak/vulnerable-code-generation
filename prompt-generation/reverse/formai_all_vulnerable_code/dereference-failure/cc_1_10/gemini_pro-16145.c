//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into a binary tree
struct node* insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search for a node in a binary tree
struct node* search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to find the minimum value in a binary tree
struct node* find_min(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Function to find the maximum value in a binary tree
struct node* find_max(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Function to delete a node from a binary tree
struct node* delete_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else {
        root->right = delete_node(root->right, data);
    }
    return root;
}

// Function to print a binary tree in preorder traversal
void preorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Function to print a binary tree in inorder traversal
void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Function to print a binary tree in postorder traversal
void postorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Search for a node in the binary tree
    struct node *found_node = search_node(root, 15);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    // Find the minimum value in the binary tree
    struct node *min_node = find_min(root);
    if (min_node != NULL) {
        printf("Minimum value: %d\n", min_node->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Find the maximum value in the binary tree
    struct node *max_node = find_max(root);
    if (max_node != NULL) {
        printf("Maximum value: %d\n", max_node->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Delete a node from the binary tree
    root = delete_node(root, 15);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}