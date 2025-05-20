//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 5
#define MAX_NAME_LEN 20

// Declare a struct to hold the state of the recursive function
struct node {
    char name[MAX_NAME_LEN];
    int depth;
    struct node* left, *right;
};

// Declare a function to create a new node
struct node* new_node(char* name, int depth) {
    struct node* node = malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->depth = depth;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Declare a function to print the tree
void print_tree(struct node* root) {
    if (root == NULL) {
        printf("( null )\n");
        return;
    }

    printf("%s%d ", root->name, root->depth);

    if (root->left != NULL) {
        print_tree(root->left);
        printf(" <- ");
    }

    if (root->right != NULL) {
        print_tree(root->right);
        printf(" -> ");
    }

    printf("\n");
}

// Declare the main function
int main() {
    struct node* root = NULL;

    // Create the root node
    root = new_node("A", 1);

    // Create the left and right subtrees
    root->left = new_node("B", 2);
    root->right = new_node("C", 3);

    // Print the tree
    print_tree(root);

    return 0;
}