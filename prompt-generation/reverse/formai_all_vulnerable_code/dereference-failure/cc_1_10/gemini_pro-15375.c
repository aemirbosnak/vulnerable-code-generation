//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the binary search tree
struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

// Function to create a new node in the binary search tree
struct bst_node *create_node(int data) {
    struct bst_node *new_node = (struct bst_node *)malloc(sizeof(struct bst_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the binary search tree
struct bst_node *insert_node(struct bst_node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct bst_node *search_node(struct bst_node *root, int data) {
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

// Function to find the minimum value in the binary search tree
struct bst_node *find_minimum(struct bst_node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value in the binary search tree
struct bst_node *find_maximum(struct bst_node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct bst_node *delete_node(struct bst_node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            struct bst_node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct bst_node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct bst_node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Function to print the binary search tree in preorder traversal
void preorder_traversal(struct bst_node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to print the binary search tree in inorder traversal
void inorder_traversal(struct bst_node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function to print the binary search tree in postorder traversal
void postorder_traversal(struct bst_node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct bst_node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    struct bst_node *node = search_node(root, 15);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    struct bst_node *min = find_minimum(root);
    if (min != NULL) {
        printf("Minimum value: %d\n", min->data);
    }

    struct bst_node *max = find_maximum(root);
    if (max != NULL) {
        printf("Maximum value: %d\n", max->data);
    }

    root = delete_node(root, 15);
    printf("After deleting the node with value 15:\n");
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    return 0;
}