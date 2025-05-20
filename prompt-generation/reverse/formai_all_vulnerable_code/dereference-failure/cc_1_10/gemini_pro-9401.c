//GEMINI-pro DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data type for a node in a binary tree
typedef struct node {
    char *data;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new node with the given data
node_t *new_node(char *data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = strdup(data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into a binary tree
node_t *insert_node(node_t *root, char *data) {
    if (root == NULL) {
        return new_node(data);
    }
    if (strcmp(data, root->data) < 0) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search for a node in a binary tree
node_t *search_node(node_t *root, char *data) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(data, root->data) == 0) {
        return root;
    }
    if (strcmp(data, root->data) < 0) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to print a binary tree in preorder traversal
void preorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%s ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Function to print a binary tree in inorder traversal
void inorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%s ", root->data);
    inorder_traversal(root->right);
}

// Function to print a binary tree in postorder traversal
void postorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%s ", root->data);
}

// Function to delete a node from a binary tree
node_t *delete_node(node_t *root, char *data) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(data, root->data) == 0) {
        // Node to be deleted is the root node
        if (root->left == NULL) {
            // Node to be deleted has no left child
            node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node to be deleted has no right child
            node_t *temp = root->left;
            free(root);
            return temp;
        } else {
            // Node to be deleted has both left and right children
            node_t *temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            root->data = temp->data;
            root->left = delete_node(root->left, temp->data);
        }
    } else if (strcmp(data, root->data) < 0) {
        root->left = delete_node(root->left, data);
    } else {
        root->right = delete_node(root->right, data);
    }
    return root;
}

// Function to free the memory allocated for a binary tree
void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root->data);
    free(root);
}

int main() {
    // Create a binary tree
    node_t *root = NULL;
    root = insert_node(root, "50");
    root = insert_node(root, "30");
    root = insert_node(root, "70");
    root = insert_node(root, "20");
    root = insert_node(root, "40");
    root = insert_node(root, "60");
    root = insert_node(root, "80");

    // Search for a node in the binary tree
    node_t *found_node = search_node(root, "40");
    if (found_node != NULL) {
        printf("Node with data %s found in the binary tree.\n", found_node->data);
    } else {
        printf("Node with data 40 not found in the binary tree.\n");
    }

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

    // Delete a node from the binary tree
    root = delete_node(root, "30");

    // Print the binary tree in inorder traversal after deleting a node
    printf("Inorder traversal after deleting node with data 30: ");
    inorder_traversal(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}