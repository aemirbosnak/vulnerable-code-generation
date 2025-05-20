//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: cheerful
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
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
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
    } else {
        return search_node(root->right, data);
    }
}

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data for the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    printf("Enter the data to search for: ");
    scanf("%d", &data);
    struct node *found_node = search_node(root, data);
    if (found_node != NULL) {
        printf("The data %d is found in the binary search tree.\n", data);
    } else {
        printf("The data %d is not found in the binary search tree.\n", data);
    }
    return 0;
}