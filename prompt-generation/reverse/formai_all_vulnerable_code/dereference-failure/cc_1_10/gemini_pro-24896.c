//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode* create_new_node(int data) {
    struct BSTNode *new_node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct BSTNode* insert_into_bst(struct BSTNode *root, int data) {
    if (root == NULL) {
        return create_new_node(data);
    } else if (data < root->data) {
        root->left = insert_into_bst(root->left, data);
    } else if (data > root->data) {
        root->right = insert_into_bst(root->right, data);
    } else {
        printf("Data already exists in the BST.\n");
    }
    return root;
}

struct BSTNode* search_in_bst(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search_in_bst(root->left, data);
    } else if (data > root->data) {
        return search_in_bst(root->right, data);
    } else {
        return root;
    }
}

void in_order_traversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

void pre_order_traversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void post_order_traversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct BSTNode *root = NULL;
    root = insert_into_bst(root, 10);
    root = insert_into_bst(root, 5);
    root = insert_into_bst(root, 15);
    root = insert_into_bst(root, 2);
    root = insert_into_bst(root, 7);
    root = insert_into_bst(root, 12);
    root = insert_into_bst(root, 20);

    // Search for a key in the BST
    struct BSTNode *found_node = search_in_bst(root, 15);
    if (found_node != NULL) {
        printf("Key found in the BST.\n");
    } else {
        printf("Key not found in the BST.\n");
    }

    // In-order traversal of the BST
    printf("In-order traversal: ");
    in_order_traversal(root);
    printf("\n");

    // Pre-order traversal of the BST
    printf("Pre-order traversal: ");
    pre_order_traversal(root);
    printf("\n");

    // Post-order traversal of the BST
    printf("Post-order traversal: ");
    post_order_traversal(root);
    printf("\n");

    return 0;
}