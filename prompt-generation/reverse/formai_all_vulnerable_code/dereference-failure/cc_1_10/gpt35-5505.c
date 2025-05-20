//FormAI DATASET v1.0 Category: Binary search trees ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *create_tree_node(int data) {
    struct tree_node *new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct tree_node *insert_node(struct tree_node *root, int data) {
    if (root == NULL) {
        return create_tree_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void print_inorder(struct tree_node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

struct tree_node *search_node(struct tree_node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    }
    return search_node(root->right, data);
}

int main() {
    struct tree_node *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Inorder traversal of binary search tree is: ");
    print_inorder(root);
    printf("\n");
    printf("Searching for node with data value of 60\n");
    struct tree_node *searched_node = search_node(root, 60);
    if (searched_node != NULL) {
        printf("Found node with data value of 60\n");
    }
    else {
        printf("Could not find node with data value of 60\n");
    }
    return 0;
}