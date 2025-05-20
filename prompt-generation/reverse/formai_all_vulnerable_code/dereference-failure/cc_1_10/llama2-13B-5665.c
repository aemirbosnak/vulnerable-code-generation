//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NODES 1000
#define MAX_KEY_LEN 20

typedef struct node {
    int key;
    char name[MAX_KEY_LEN];
    struct node *left;
    struct node *right;
} node_t;

node_t* init_tree(void) {
    node_t *root = malloc(sizeof(node_t));
    root->key = 0;
    root->name[0] = '\0';
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insert_node(node_t **tree, int key, char *name) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    strcpy(new_node->name, name);

    if (*tree == NULL) {
        *tree = new_node;
        return;
    }

    if (key < (*tree)->key) {
        (*tree)->left = new_node;
    } else if (key > (*tree)->key) {
        (*tree)->right = new_node;
    } else {
        strcpy(new_node->name, (*tree)->name);
        free(*tree);
        *tree = new_node;
    }
}

void traverse_tree(node_t *tree) {
    if (tree == NULL) {
        return;
    }

    printf("%d: %s\n", tree->key, tree->name);

    traverse_tree(tree->left);
    traverse_tree(tree->right);
}

int main(void) {
    node_t *tree = init_tree();

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int key = rand() % 100;
        char name[MAX_KEY_LEN];
        snprintf(name, MAX_KEY_LEN, "Key %d", key);
        insert_node(&tree, key, name);
    }

    traverse_tree(tree);

    free(tree);
    return 0;
}