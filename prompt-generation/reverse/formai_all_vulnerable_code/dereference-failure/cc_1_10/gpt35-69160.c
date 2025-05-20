//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node node;

node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

node* search(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    node *root = NULL;
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 3);
    insert(&root, 1);
    inorder_traversal(root);
    printf("\n");
    node *search_result = search(root, 9);
    if (search_result != NULL) {
        printf("Found node with data = %d\n", search_result->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}