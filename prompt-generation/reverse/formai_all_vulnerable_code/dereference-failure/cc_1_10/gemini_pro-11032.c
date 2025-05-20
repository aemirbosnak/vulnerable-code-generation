//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

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
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    }
    return NULL;
}

void print_inorder(struct node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

void print_preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(struct node *root) {
    if (root != NULL) {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data for each node:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\nPreorder traversal: ");
    print_preorder(root);
    printf("\nPostorder traversal: ");
    print_postorder(root);
    printf("\nEnter the data to search: ");
    scanf("%d", &data);
    struct node *found_node = search_node(root, data);
    if (found_node != NULL) {
        printf("Node found!\n");
    } else {
        printf("Node not found!\n");
    }
    return 0;
}