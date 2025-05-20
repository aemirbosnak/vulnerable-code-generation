//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* create_node(int data) {
    Tree* node = (Tree*) malloc(sizeof(Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Tree** root, int data) {
    if (*root == NULL) { // If tree is empty
        *root = create_node(data);
    }
    else if (data < (*root)->data) { // Data is smaller than root
        insert_node(&((*root)->left), data);
    }
    else if (data > (*root)->data) { // Data is greater than root
        insert_node(&((*root)->right), data);
    }
}

void print_tree(Tree* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    print_tree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, space);
}

int main() {
    Tree* root = NULL;
    
    // Insert nodes into the tree
    insert_node(&root, 30);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 10);
    insert_node(&root, 25);
    insert_node(&root, 35);
    insert_node(&root, 50);

    // Print the tree
    print_tree(root, 0);

    return 0;
}