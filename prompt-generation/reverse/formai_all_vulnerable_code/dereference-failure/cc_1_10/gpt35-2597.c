//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_node {
    int value;
    struct _tree_node* left_child;
    struct _tree_node* right_child;
} tree_node;

tree_node* create_node(int value){
    tree_node* node = (tree_node*)malloc(sizeof(tree_node));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

void insert_node(tree_node** root, int value){
    if (*root == NULL){
        *root = create_node(value);
        return;
    }

    if (value < (*root)->value)
        insert_node(&((*root)->left_child), value);
    else
        insert_node(&((*root)->right_child), value);
}

void print_tree(tree_node* root){
    if (root != NULL){
        print_tree(root->left_child);
        printf("%d ", root->value);
        print_tree(root->right_child);
    }
}

void destroy_tree(tree_node* root){
     if (root != NULL){
        destroy_tree(root->left_child);
        destroy_tree(root->right_child);
        free(root);
     }
}

int main(){
    tree_node* root = NULL;

    insert_node(&root, 5);
    insert_node(&root, 8);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 10);
    insert_node(&root, 7);

    printf("In the post-apocalyptic world, the only way to store valuable information was through a binary search tree.\n");
    printf("The following is a print out of the data stored in the tree:\n");

    print_tree(root);

    printf("\n\nBut alas, resources are scarce and all must be destroyed.\n");

    destroy_tree(root);

    return 0;
}