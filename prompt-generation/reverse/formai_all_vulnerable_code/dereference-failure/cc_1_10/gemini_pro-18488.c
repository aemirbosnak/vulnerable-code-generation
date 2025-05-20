//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(char *key, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node_t **root, char *key, int value) {
    if (*root == NULL) {
        *root = create_node(key, value);
        return;
    }
    if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key, value);
    } else {
        insert_node(&(*root)->right, key, value);
    }
}

node_t *find_node(node_t *root, char *key) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(key, root->key) == 0) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        return find_node(root->left, key);
    } else {
        return find_node(root->right, key);
    }
}

void delete_node(node_t **root, char *key) {
    if (*root == NULL) {
        return;
    }
    if (strcmp(key, (*root)->key) == 0) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            node_t *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            node_t *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            node_t *temp = (*root)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            (*root)->key = temp->key;
            (*root)->value = temp->value;
            delete_node(&(*root)->left, temp->key);
        }
    } else if (strcmp(key, (*root)->key) < 0) {
        delete_node(&(*root)->left, key);
    } else {
        delete_node(&(*root)->right, key);
    }
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%s: %d\n", root->key, root->value);
    print_tree(root->right);
}

int main() {
    node_t *root = NULL;

    insert_node(&root, "apple", 1);
    insert_node(&root, "banana", 2);
    insert_node(&root, "cherry", 3);
    insert_node(&root, "dog", 4);
    insert_node(&root, "elephant", 5);

    print_tree(root);

    node_t *found_node = find_node(root, "apple");
    if (found_node != NULL) {
        printf("Found node: %s: %d\n", found_node->key, found_node->value);
    }

    delete_node(&root, "apple");

    print_tree(root);

    return 0;
}