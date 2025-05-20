//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new binary tree node
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary search tree
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

// Search for a node in a binary search tree
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

// Find the minimum value in a binary search tree
struct node* find_min(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in a binary search tree
struct node* find_max(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Delete a node from a binary search tree
struct node* delete_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Node to be deleted has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Node to be deleted has one child
        else if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        // Node to be deleted has two children
        else {
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Print a binary search tree in preorder traversal
void preorder_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print a binary search tree in inorder traversal
void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print a binary search tree in postorder traversal
void postorder_traversal(struct node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Search for a node in the binary search tree
    struct node *node = search_node(root, 40);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Find the minimum value in the binary search tree
    struct node *min_node = find_min(root);
    if (min_node != NULL) {
        printf("Minimum value: %d\n", min_node->data);
    }

    // Find the maximum value in the binary search tree
    struct node *max_node = find_max(root);
    if (max_node != NULL) {
        printf("Maximum value: %d\n", max_node->data);
    }

    // Delete a node from the binary search tree
    root = delete_node(root, 40);

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}