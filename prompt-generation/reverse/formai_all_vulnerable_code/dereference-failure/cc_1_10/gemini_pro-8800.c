//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
    }
    return root;
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int data[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 11, 13, 16, 18};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insert_node(root, data[i]);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n");
    int search_key = 15;
    struct node *found_node = search_node(root, search_key);
    if (found_node != NULL) {
        printf("The node with data %d was found in the binary search tree.\n", search_key);
    } else {
        printf("The node with data %d was not found in the binary search tree.\n", search_key);
    }
    return 0;
}