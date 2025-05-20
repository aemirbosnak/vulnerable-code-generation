//GEMINI-pro DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the binary tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Find the minimum value in the binary tree
struct node *find_min(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in the binary tree
struct node *find_max(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Find the height of the binary tree
int find_height(struct node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Print the binary tree in preorder traversal
void preorder_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print the binary tree in inorder traversal
void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print the binary tree in postorder traversal
void postorder_traversal(struct node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Free the memory allocated for the binary tree
void free_tree(struct node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    // Create the root node of the binary tree
    struct node *root = create_node(10);

    // Insert some values into the binary tree
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 18);

    // Find the minimum and maximum values in the binary tree
    struct node *min = find_min(root);
    struct node *max = find_max(root);

    // Find the height of the binary tree
    int height = find_height(root);

    // Print the binary tree in preorder, inorder, and postorder traversals
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}