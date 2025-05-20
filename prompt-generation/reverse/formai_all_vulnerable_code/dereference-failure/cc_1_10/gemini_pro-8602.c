//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// A node in a binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node *new_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into a binary search tree
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return new_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
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

// Find a node with the given data in a binary search tree
struct node *find(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return find(root->left, data);
    } else {
        return find(root->right, data);
    }
}

// Delete a node from a binary search tree
struct node *delete(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // If the node has no children, simply delete it
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // If the node has one child, replace it with its child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            root = temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            root = temp;
        }
        // If the node has two children, replace it with its successor
        else {
            struct node *successor = find_min(root->right);
            root->data = successor->data;
            root->right = delete(root->right, successor->data);
        }
    }
    return root;
}

// Print a binary search tree in order
void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Print a binary search tree in preorder
void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

// Print a binary search tree in postorder
void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree in order
    printf("Inorder: ");
    print_inorder(root);
    printf("\n");

    // Print the binary search tree in preorder
    printf("Preorder: ");
    print_preorder(root);
    printf("\n");

    // Print the binary search tree in postorder
    printf("Postorder: ");
    print_postorder(root);
    printf("\n");

    // Find the minimum value in the binary search tree
    struct node *min = find_min(root);
    printf("Minimum value: %d\n", min->data);

    // Find the maximum value in the binary search tree
    struct node *max = find_max(root);
    printf("Maximum value: %d\n", max->data);

    // Find a node with the given data in the binary search tree
    struct node *found = find(root, 40);
    if (found != NULL) {
        printf("Node with data 40 found\n");
    } else {
        printf("Node with data 40 not found\n");
    }

    // Delete a node from the binary search tree
    root = delete(root, 40);

    // Print the binary search tree in order
    printf("Inorder (after deleting 40): ");
    print_inorder(root);
    printf("\n");

    return 0;
}