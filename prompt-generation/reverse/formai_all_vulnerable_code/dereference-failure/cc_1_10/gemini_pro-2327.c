//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *key;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *key) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = strdup(key);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, char *key) {
    if (*root == NULL) {
        *root = create_node(key);
    } else if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key);
    } else if (strcmp(key, (*root)->key) > 0) {
        insert_node(&(*root)->right, key);
    }
}

struct node *search_node(struct node *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) < 0) {
        return search_node(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        return search_node(root->right, key);
    } else {
        return root;
    }
}

void print_node(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_node(root->left);
    printf("%s\n", root->key);
    print_node(root->right);
}

void free_node(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_node(root->left);
    free_node(root->right);
    free(root->key);
    free(root);
}

int main() {
    struct node *root = NULL;

    insert_node(&root, "Romeo");
    insert_node(&root, "Juliet");
    insert_node(&root, "Tybalt");
    insert_node(&root, "Mercutio");
    insert_node(&root, "Friar Laurence");
    insert_node(&root, "Paris");

    print_node(root);

    struct node *romeo = search_node(root, "Romeo");
    if (romeo != NULL) {
        printf("Found Romeo!\n");
    }

    struct node *juliet = search_node(root, "Juliet");
    if (juliet != NULL) {
        printf("Found Juliet!\n");
    }

    free_node(root);

    return 0;
}