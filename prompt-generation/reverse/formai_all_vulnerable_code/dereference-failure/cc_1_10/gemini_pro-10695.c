//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: puzzling
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
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    node *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert_node(&root, data);
    }
    printf("Inorder traversal of the tree: ");
    print_tree(root);
    printf("\n");
    int data;
    printf("Enter the data to search for: ");
    scanf("%d", &data);
    node *found_node = search_node(root, data);
    if (found_node != NULL) {
        printf("Node with data %d found!\n", found_node->data);
    } else {
        printf("Node with data %d not found!\n", data);
    }
    return 0;
}