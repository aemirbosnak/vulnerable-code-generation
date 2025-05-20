//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

node *search_node(node *root, int data) {
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

void print_tree(node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    node *root = NULL;
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++) {
        insert_node(&root, data[i]);
    }
    print_tree(root);
    printf("\n");
    node *found_node = search_node(root, 60);
    if (found_node != NULL) {
        printf("Found node with data: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}