//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a node in the binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary tree
node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Print the binary tree in preorder traversal order
void preorder_traversal(node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print the binary tree in inorder traversal order
void inorder_traversal(node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print the binary tree in postorder traversal order
void postorder_traversal(node_t *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Find the minimum value in the binary tree
node_t *find_min(node_t *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in the binary tree
node_t *find_max(node_t *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Find the height of the binary tree
int find_height(node_t *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Check if the binary tree is a binary search tree
int is_bst(node_t *root) {
    if (root == NULL) {
        return 1;
    } else if (root->left != NULL && root->left->data > root->data) {
        return 0;
    } else if (root->right != NULL && root->right->data < root->data) {
        return 0;
    } else {
        return is_bst(root->left) && is_bst(root->right);
    }
}

// Delete a node with the given data from the binary tree
node_t *delete_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t *temp = root->left;
            free(root);
            return temp;
        } else {
            node_t *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Free the memory allocated for the binary tree
void free_tree(node_t *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Main function to test the binary tree functions
int main() {
    // Create a binary tree
    node_t *root = create_node(10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    // Print the binary tree in preorder traversal order
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in inorder traversal order
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in postorder traversal order
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Find the minimum value in the binary tree
    node_t *min_node = find_min(root);
    printf("Minimum value: %d\n", min_node->data);

    // Find the maximum value in the binary tree
    node_t *max_node = find_max(root);
    printf("Maximum value: %d\n", max_node->data);

    // Find the height of the binary tree
    int height = find_height(root);
    printf("Height of the binary tree: %d\n", height);

    // Check if the binary tree is a binary search tree
    int is_bst_result = is_bst(root);
    printf("Is the binary tree a binary search tree? %s\n", is_bst_result ? "Yes" : "No");

    // Delete a node from the binary tree
    root = delete_node(root, 15);

    // Print the binary tree in inorder traversal order
    printf("Inorder traversal after deleting node 15: ");
    inorder_traversal(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}