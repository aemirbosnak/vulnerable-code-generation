//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_KEYS 1000

typedef struct node {
    int key;
    struct node *left, *right;
} node_t;

node_t* create_node(int key) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(node_t** root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
    } else {
        if (key < (*root)->key) {
            insert_node(&(*root)->left, key);
        } else {
            insert_node(&(*root)->right, key);
        }
    }
}

int find_node(node_t* root, int key) {
    if (root == NULL) {
        return -1;
    }

    if (key < root->key) {
        return find_node(root->left, key);
    } else if (key > root->key) {
        return find_node(root->right, key);
    } else {
        return 0;
    }
}

void delete_node(node_t** root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        delete_node(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete_node(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            (*root)->right = NULL;
        } else if ((*root)->right == NULL) {
            (*root)->left = NULL;
        } else {
            node_t* min = NULL;
            node_t* temp = (*root)->left;
            while (temp->right != NULL) {
                min = temp;
                temp = temp->right;
            }
            temp->right = NULL;
            (*root)->left = min;
        }
    }
}

int main() {
    node_t* root = NULL;

    insert_node(&root, 5);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 2);
    insert_node(&root, 9);

    int key = 7;
    int found = find_node(root, key);
    if (found != -1) {
        printf("Found node with key %d\n", found);
    } else {
        printf("Node not found\n");
    }

    delete_node(&root, 7);

    return 0;
}