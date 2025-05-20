//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

void print_tree(node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_tree(root->left);
        print_tree(root->right);
    }
}

node_t *search_node(node_t *root, int data) {
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

node_t *delete_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t *temp = root->left;
            free(root);
            return temp;
        } else {
            node_t *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    node_t *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 17);

    printf("The tree is: ");
    print_tree(root);
    printf("\n");

    node_t *found_node = search_node(root, 15);
    if (found_node != NULL) {
        printf("Found node: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    root = delete_node(root, 15);

    printf("The tree after deleting 15 is: ");
    print_tree(root);
    printf("\n");

    return 0;
}