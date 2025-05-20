//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node struct
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Tree struct
struct tree {
    struct node* root;
};

// Function to add a node to the binary tree
void add_node(struct tree* tree, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct node* curr_node = tree->root;
        while (curr_node->left!= NULL) {
            curr_node = curr_node->left;
        }
        curr_node->left = new_node;
    }
}

// Function to visualize the binary tree
void visualize_tree(struct tree* tree) {
    struct node* curr_node = tree->root;
    int i = 0;
    while (curr_node!= NULL) {
        printf(" ");
        for (i = 0; i < (curr_node->data + 1); i++) {
            printf("#");
        }
        printf("\n");
        curr_node = curr_node->left;
    }
    
    while (curr_node!= NULL) {
        printf(" ");
        for (i = 0; i < (curr_node->data + 1); i++) {
            printf("#");
        }
        printf("\n");
        curr_node = curr_node->right;
    }
}

int main() {
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    
    add_node(tree, 1);
    add_node(tree, 2);
    add_node(tree, 3);
    add_node(tree, 4);
    add_node(tree, 5);
    add_node(tree, 6);
    add_node(tree, 7);
    add_node(tree, 8);
    add_node(tree, 9);
    add_node(tree, 10);
    
    visualize_tree(tree);
    
    return 0;
}