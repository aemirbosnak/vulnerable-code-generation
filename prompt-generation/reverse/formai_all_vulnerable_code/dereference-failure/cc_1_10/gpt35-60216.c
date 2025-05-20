//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

struct node *create_node(int value) {
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void insert(struct node **root, int value) {
    if(*root == NULL) {
        *root = create_node(value);
        return;
    }

    if(value < (*root)->value) {
        insert(&(*root)->left_child, value);
    } else {
        insert(&(*root)->right_child, value);
    }
}

void print_tree(struct node *root) {
    if(root == NULL) {
        return;
    }

    printf("%d ", root->value);
    print_tree(root->left_child);
    print_tree(root->right_child);
}

int main() {
    struct node *root = NULL;
    int values[] = {10, 7, 15, 3, 4, 1, 2, 9, 8, 12, 13, 18};

    for(int i = 0; i < 12; i++) {
        insert(&root, values[i]);
    }

    printf("The Medieval Binary Search Tree:\n");
    print_tree(root);

    return 0;
}