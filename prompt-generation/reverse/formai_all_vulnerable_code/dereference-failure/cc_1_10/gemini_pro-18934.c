//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

node *create_node(int val) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int val) {
    if (*root == NULL) {
        *root = create_node(val);
    } else if (val < (*root)->val) {
        insert_node(&(*root)->left, val);
    } else {
        insert_node(&(*root)->right, val);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    print_tree(root->left);
    print_tree(root->right);
}

int search_tree(node *root, int val) {
    if (root == NULL) {
        return 0;
    }
    if (root->val == val) {
        return 1;
    } else if (val < root->val) {
        return search_tree(root->left, val);
    } else {
        return search_tree(root->right, val);
    }
}

int main() {
    node *root = NULL;
    int i, val;

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        val = rand() % 100;
        insert_node(&root, val);
    }

    print_tree(root);
    printf("\n");

    val = rand() % 100;
    if (search_tree(root, val)) {
        printf("Found value %d in the tree.\n", val);
    } else {
        printf("Value %d not found in the tree.\n", val);
    }

    return 0;
}