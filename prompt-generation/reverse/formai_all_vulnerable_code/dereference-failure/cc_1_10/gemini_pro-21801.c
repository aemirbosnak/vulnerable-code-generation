//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct tree {
    node *root;
} tree;

node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree *create_tree() {
    tree *new_tree = malloc(sizeof(tree));
    new_tree->root = NULL;
    return new_tree;
}

void insert_node(tree *t, int data) {
    node *new_node = create_node(data);

    if (t->root == NULL) {
        t->root = new_node;
    } else {
        node *current_node = t->root;

        while (1) {
            if (data < current_node->data) {
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == NULL) {
                    current_node->right = new_node;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
        }
    }
}

void inorder_traversal(node *n) {
    if (n != NULL) {
        inorder_traversal(n->left);
        printf("%d ", n->data);
        inorder_traversal(n->right);
    }
}

int main() {
    tree *t = create_tree();

    insert_node(t, 50);
    insert_node(t, 30);
    insert_node(t, 70);
    insert_node(t, 20);
    insert_node(t, 40);
    insert_node(t, 60);
    insert_node(t, 80);

    inorder_traversal(t->root);

    return 0;
}