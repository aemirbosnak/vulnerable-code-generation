//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the binary tree
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

// Search for a node with the given data in the binary tree
struct node *search_node(struct node *root, int data) {
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
void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

// Print the binary tree in inorder traversal
void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Print the binary tree in postorder traversal
void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

// Free the memory allocated to the binary tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Main function
int main() {
    // Create the binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    print_postorder(root);
    printf("\n");

    // Find the minimum value in the binary tree
    struct node *min_node = find_min(root);
    printf("Minimum value: %d\n", min_node->data);

    // Find the maximum value in the binary tree
    struct node *max_node = find_max(root);
    printf("Maximum value: %d\n", max_node->data);

    // Find the height of the binary tree
    int height = find_height(root);
    printf("Height of the binary tree: %d\n", height);

    // Search for a node with the given data in the binary tree
    struct node *search_result = search_node(root, 12);
    if (search_result == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found: %d\n", search_result->data);
    }

    // Free the memory allocated to the binary tree
    free_tree(root);

    return 0;
}