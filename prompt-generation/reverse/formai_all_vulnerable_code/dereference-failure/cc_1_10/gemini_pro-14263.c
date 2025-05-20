//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary search tree
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

// Find a node in a binary search tree
struct node *find_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return find_node(root->left, data);
    } else {
        return find_node(root->right, data);
    }
}

// Delete a node from a binary search tree
struct node *delete_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            // Node has no left child
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node has no right child
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            // Node has both left and right children
            struct node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Print a binary search tree in preorder traversal
void preorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Print a binary search tree in inorder traversal
void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Print a binary search tree in postorder traversal
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
    // Create a binary search tree
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Find a node in the binary search tree
    struct node *found_node = find_node(root, 40);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the binary search tree
    root = delete_node(root, 20);

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