//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a node for a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
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

// Print a binary tree using a pre-order traversal
void print_tree_pre_order(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_tree_pre_order(root->left);
        print_tree_pre_order(root->right);
    }
}

// Print a binary tree using an in-order traversal
void print_tree_in_order(struct node *root) {
    if (root != NULL) {
        print_tree_in_order(root->left);
        printf("%d ", root->data);
        print_tree_in_order(root->right);
    }
}

// Print a binary tree using a post-order traversal
void print_tree_post_order(struct node *root) {
    if (root != NULL) {
        print_tree_post_order(root->left);
        print_tree_post_order(root->right);
        printf("%d ", root->data);
    }
}

// Draw a binary tree using a ASCII representation
void draw_tree(struct node *root, int depth) {
    if (root != NULL) {
        draw_tree(root->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        draw_tree(root->left, depth + 1);
    }
}

// Main function
int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the binary tree using a pre-order traversal
    printf("Pre-order traversal: ");
    print_tree_pre_order(root);
    printf("\n");

    // Print the binary tree using an in-order traversal
    printf("In-order traversal: ");
    print_tree_in_order(root);
    printf("\n");

    // Print the binary tree using a post-order traversal
    printf("Post-order traversal: ");
    print_tree_post_order(root);
    printf("\n");

    // Draw the binary tree using ASCII representation
    printf("ASCII representation of the tree:\n");
    draw_tree(root, 0);

    return 0;
}