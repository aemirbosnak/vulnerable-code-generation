//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int key;
    int value;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int key, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node_t **root, int key, int value) {
    if (*root == NULL) {
        *root = create_node(key, value);
        return;
    }

    if (key < (*root)->key) {
        insert_node(&(*root)->left, key, value);
    } else if (key > (*root)->key) {
        insert_node(&(*root)->right, key, value);
    } else {
        (*root)->value = value;
    }
}

node_t *find_node(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        return find_node(root->left, key);
    } else if (key > root->key) {
        return find_node(root->right, key);
    } else {
        return root;
    }
}

void delete_node(node_t **root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        delete_node(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete_node(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL) {
            node_t *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            node_t *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            node_t *temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            (*root)->key = temp->key;
            (*root)->value = temp->value;

            delete_node(&(*root)->right, temp->key);
        }
    }
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("(%d, %d) ", root->key, root->value);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    node_t *root = NULL;

    insert_node(&root, 10, 10);
    insert_node(&root, 5, 5);
    insert_node(&root, 15, 15);
    insert_node(&root, 2, 2);
    insert_node(&root, 7, 7);
    insert_node(&root, 12, 12);
    insert_node(&root, 20, 20);

    print_tree(root);
    printf("\n");

    node_t *found_node = find_node(root, 15);
    if (found_node != NULL) {
        printf("Found node with key %d and value %d\n", found_node->key, found_node->value);
    } else {
        printf("Node not found\n");
    }

    delete_node(&root, 15);

    print_tree(root);
    printf("\n");

    return 0;
}