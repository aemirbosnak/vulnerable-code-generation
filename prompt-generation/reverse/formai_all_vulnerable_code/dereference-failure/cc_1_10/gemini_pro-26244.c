//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
        return root;
    }
}

node* search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else {
        if (data == root->data) {
            return root;
        } else if (data <= root->data) {
            return search_node(root->left, data);
        } else {
            return search_node(root->right, data);
        }
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    } else {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    node *root = NULL;
    int data[] = {10, 5, 15, 2, 7, 12, 20};
    int i;

    for (i = 0; i < 7; i++) {
        root = insert_node(root, data[i]);
    }

    printf("Inorder traversal of the tree: ");
    print_tree(root);
    printf("\n");

    int search_data = 15;
    node *found_node = search_node(root, search_data);
    if (found_node == NULL) {
        printf("%d not found in the tree.\n", search_data);
    } else {
        printf("%d found in the tree.\n", search_data);
    }

    return 0;
}