//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
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

// Function to find the height of the binary tree
int find_height(node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Function to check if the binary tree is balanced
int is_balanced(node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return (abs(left_height - right_height) <= 1) && is_balanced(root->left) && is_balanced(root->right);
    }
}

// Function to print the binary tree in preorder traversal
void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to print the binary tree in inorder traversal
void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    } else {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function to print the binary tree in postorder traversal
void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    } else {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the memory allocated to the binary tree
void free_tree(node *root) {
    if (root == NULL) {
        return;
    } else {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

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

    // Find the minimum value in the binary tree
    node *min_node = find_min(root);
    printf("Minimum value: %d\n", min_node->data);

    // Find the maximum value in the binary tree
    node *max_node = find_max(root);
    printf("Maximum value: %d\n", max_node->data);

    // Find the height of the binary tree
    int height = find_height(root);
    printf("Height of the binary tree: %d\n", height);

    // Check if the binary tree is balanced
    int is_balanced_tree = is_balanced(root);
    printf("Is the binary tree balanced? %d\n", is_balanced_tree);

    // Free the memory allocated to the binary tree
    free_tree(root);

    return 0;
}