//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    } else {
        fprintf(stderr, "Error: duplicate value.\n");
        exit(1);
    }
    return root;
}

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    } else {
        return root;
    }
}

void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

void print_preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(int argc, char **argv) {
    node *root = NULL;
    int i;
    int arr[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 11, 13, 16, 18};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < len; i++) {
        root = insert_node(root, arr[i]);
    }

    printf("Inorder traversal:\n");
    print_inorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    print_preorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    print_postorder(root);
    printf("\n");

    printf("Searching for 10:\n");
    node *found_node = search_node(root, 10);
    if (found_node == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found: %d\n", found_node->data);
    }

    free_tree(root);
    return 0;
}