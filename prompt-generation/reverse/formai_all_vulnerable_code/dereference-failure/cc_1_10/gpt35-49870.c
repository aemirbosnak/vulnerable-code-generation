//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_t;

void insert(node_t** root_ref, int value) {
    if (*root_ref == NULL) {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        *root_ref = new_node;
    } else {
        if (value < (*root_ref)->value) {
            insert(&((*root_ref)->left), value);
        } else {
            insert(&((*root_ref)->right), value);
        }
    }
}

void print_in_order(node_t* root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("%d ", root->value);
        print_in_order(root->right);
    }
}

int main() {
    node_t* root = NULL;
    // insert some sample values
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    // print the tree in order
    printf("In Order: ");
    print_in_order(root);
    printf("\n");

    return 0;
}