//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
}   *node;

node create_node(int value) {
    node new_node = (node) malloc(sizeof(struct tree_node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

node insert_node(node root, int value) {
    if (root == NULL) {
        return (create_node(value));
    }
    if (value < root->data) {
        root->left = insert_node(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert_node(root->right, value);
    }
    return (root);
}

void inorder_traversal(node root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

node search_node(node root, int value) {
    if (root == NULL || root->data == value) {
        return (root);
    }
    if (value < root->data) {
        return (search_node(root->left, value));
    }
    else {
        return (search_node(root->right, value));
    }
}

node find_min_value(node root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return (root);
}

node delete_node(node root, int value) {
    if (root == NULL) {
        return (root);
    }
    if (value < root->data) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return (temp);
        }
        else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return (temp);
        }
        node temp = find_min_value(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return (root);
}

int main() {
    node root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\nSearching for 40 in the tree: ");
    node search_result = search_node(root, 40);
    if (search_result != NULL) {
        printf("Found!");
    }
    else {
        printf("Not Found!");
    }
    printf("\nDeleting 40 from the tree...\n");
    root = delete_node(root, 40);
    printf("New Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    return (0);
}