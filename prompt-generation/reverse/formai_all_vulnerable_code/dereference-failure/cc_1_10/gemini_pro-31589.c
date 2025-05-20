//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_NODES 100

struct node {
    char *key;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *key) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = strdup(key);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void destroy_node(struct node *node) {
    if (node == NULL) {
        return;
    }

    free(node->key);
    free(node);
}

void insert_node(struct node **root, char *key) {
    if (*root == NULL) {
        *root = create_node(key);
        return;
    }

    if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key);
    } else {
        insert_node(&(*root)->right, key);
    }
}

struct node *search_node(struct node *root, char *key) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(key, root->key) == 0) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

void print_node(struct node *node) {
    if (node == NULL) {
        return;
    }

    printf("%s\n", node->key);
}

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    print_node(root);
    print_tree(root->right);
}

void destroy_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    destroy_node(root);
}

int main() {
    srand(time(NULL));

    struct node *root = NULL;

    char *keys[] = {
        "apple", "banana", "cherry", "dog", "elephant",
        "fish", "grape", "horse", "ice cream", "juice"
    };

    for (int i = 0; i < 10; i++) {
        int index = rand() % 10;
        insert_node(&root, keys[index]);
    }

    print_tree(root);

    char *key = "banana";
    struct node *node = search_node(root, key);

    if (node != NULL) {
        printf("Found key: %s\n", node->key);
    } else {
        printf("Key not found: %s\n", key);
    }

    destroy_tree(root);

    return 0;
}