//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

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

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node *search_node(node *root, int data) {
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

void print_inorder(node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

void print_preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(node *root) {
    if (root != NULL) {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node *root = NULL;
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int i;

    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        root = insert_node(root, data[i]);
    }

    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    print_postorder(root);
    printf("\n");

    int search_data = 40;
    node *found_node = search_node(root, search_data);
    if (found_node != NULL) {
        printf("Node with data %d found.\n", search_data);
    } else {
        printf("Node with data %d not found.\n", search_data);
    }

    return 0;
}