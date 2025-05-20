//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: genious
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

void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    node *root = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("Enter the element to search: ");
    scanf("%d", &data);
    node *found = search_node(root, data);
    if (found != NULL) {
        printf("Element found!\n");
    } else {
        printf("Element not found!\n");
    }
    return 0;
}