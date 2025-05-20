//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *key;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *key) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = strdup(key);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, char *key) {
    if (root == NULL) {
        return create_node(key);
    } else if (strcmp(key, root->key) < 0) {
        root->left = insert_node(root->left, key);
    } else {
        root->right = insert_node(root->right, key);
    }
    return root;
}

struct node *search_node(struct node *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) == 0) {
        return root;
    } else if (strcmp(key, root->key) < 0) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

void print_node(struct node *node) {
    printf("%s\n", node->key);
}

void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    print_node(root);
    print_inorder(root->right);
}

void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_node(root);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    print_node(root);
}

void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root->key);
    free(root);
}

int main() {
    struct node *root = NULL;

    root = insert_node(root, "A");
    root = insert_node(root, "B");
    root = insert_node(root, "C");
    root = insert_node(root, "D");
    root = insert_node(root, "E");

    printf("Inorder:\n");
    print_inorder(root);
    printf("\nPreorder:\n");
    print_preorder(root);
    printf("\nPostorder:\n");
    print_postorder(root);

    struct node *found_node = search_node(root, "D");
    if (found_node != NULL) {
        printf("Found node with key %s\n", found_node->key);
    } else {
        printf("Node not found\n");
    }

    free_tree(root);

    return 0;
}