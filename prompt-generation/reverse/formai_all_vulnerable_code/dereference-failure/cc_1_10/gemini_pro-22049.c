//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Search for a node in a binary search tree
struct node *search_node(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
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

// Delete a node from a binary search tree
struct node *delete_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            root = temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            root = temp;
        } else {
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

// Find the minimum value in a binary search tree
struct node *find_min(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min(root->left);
    }
}

// Find the maximum value in a binary search tree
struct node *find_max(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max(root->right);
    }
}

// Get the height of a binary search tree
int get_height(struct node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Check if a binary search tree is balanced
int is_balanced(struct node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        return abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right);
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
    struct node *found_node = search_node(root, 40);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

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

    // Delete a node from the binary search tree
    root = delete_node(root, 40);

    // Find the minimum value in the binary search tree
    struct node *min_node = find_min(root);
    if (min_node != NULL) {
        printf("Minimum value: %d\n", min_node->data);
    } else {
        printf("Minimum value not found\n");
    }

    // Find the maximum value in the binary search tree
    struct node *max_node = find_max(root);
    if (max_node != NULL) {
        printf("Maximum value: %d\n", max_node->data);
    } else {
        printf("Maximum value not found\n");
    }

    // Get the height of the binary search tree
    int height = get_height(root);
    printf("Height of the binary search tree: %d\n", height);

    // Check if the binary search tree is balanced
    int is_balanced_res = is_balanced(root);
    if (is_balanced_res) {
        printf("Binary search tree is balanced\n");
    } else {
        printf("Binary search tree is not balanced\n");
    }

    return 0;
}