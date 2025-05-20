//FormAI DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for binary search trees
struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

// Create a new node for the binary search tree
struct BST* create_node(int value) {
    struct BST* node = (struct BST*) malloc(sizeof(struct BST));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node into the binary search tree
struct BST* insert(struct BST* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Traverse the binary search tree in-order
void inorder_traversal(struct BST* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Traverse the binary search tree pre-order
void preorder_traversal(struct BST* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Traverse the binary search tree post-order
void postorder_traversal(struct BST* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Find the minimum value in a binary search tree
struct BST* find_min(struct BST* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find the maximum value in a binary search tree
struct BST* find_max(struct BST* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Find a node with a specific value in a binary search tree
struct BST* find_node(struct BST* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->data) {
        return find_node(root->left, value);
    } else if (value > root->data) {
        return find_node(root->right, value);
    } else {
        return root;
    }
}

// Delete a node with a specific value from a binary search tree
struct BST* delete_node(struct BST* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->data) {
        root->left = delete_node(root->left, value);
    } else if (value > root->data) {
        root->right = delete_node(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            struct BST* temp;
            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        } else {
            struct BST* temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Test the binary search tree
int main() {
    struct BST* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);
    printf("In-order traversal: ");
    inorder_traversal(root);
    printf("\nPre-order traversal: ");
    preorder_traversal(root);
    printf("\nPost-order traversal: ");
    postorder_traversal(root);
    printf("\nMinimum value: %d", find_min(root)->data);
    printf("\nMaximum value: %d", find_max(root)->data);
    printf("\nDeleting node with value 6...\n");
    root = delete_node(root, 6);
    printf("In-order traversal: ");
    inorder_traversal(root);
    return 0;
}