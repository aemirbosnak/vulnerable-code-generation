//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>

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

void insert_node(struct node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);
    printf("Inorder traversal of the binary search tree: ");
    print_tree(root);
    printf("\n");
    struct node *found_node = search_node(root, 15);
    if (found_node != NULL) {
        printf("The node with data 15 was found.\n");
    } else {
        printf("The node with data 15 was not found.\n");
    }
    return 0;
}