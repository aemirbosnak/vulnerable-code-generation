//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a node of the binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the binary tree
node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search for a node with the given data in the binary tree
node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to find the minimum value in the binary tree
node *find_min(node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Function to find the maximum value in the binary tree
node *find_max(node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Function to delete a node with the given data from the binary tree
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
            // Node to be deleted has two children
            node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Function to print the binary tree in preorder traversal
void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Function to print the binary tree in inorder traversal
void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Function to print the binary tree in postorder traversal
void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create the root node of the binary tree
    node *root = create_node(10);

    // Insert some nodes into the binary tree
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    // Search for a node in the binary tree
    node *found_node = search_node(root, 15);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node with data 15 not found\n");
    }

    // Find the minimum value in the binary tree
    node *min_node = find_min(root);
    printf("Minimum value in the binary tree: %d\n", min_node->data);

    // Find the maximum value in the binary tree
    node *max_node = find_max(root);
    printf("Maximum value in the binary tree: %d\n", max_node->data);

    // Delete a node from the binary tree
    root = delete_node(root, 15);
    printf("Binary tree after deleting node with data 15:\n");
    preorder_traversal(root);
    printf("\n");

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