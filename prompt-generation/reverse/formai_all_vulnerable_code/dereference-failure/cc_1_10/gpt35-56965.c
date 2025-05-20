//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
} Tree_Node;

void insert(Tree_Node **node, int value) {
    if (*node == NULL) {
        Tree_Node *new_node = (Tree_Node *) malloc(sizeof(Tree_Node));
        new_node -> value = value;
        new_node -> left = NULL;
        new_node -> right = NULL;
        *node = new_node;
    }
    else if (value < (*node) -> value) {
        insert(&((*node) -> left), value);
    }
    else {
        insert(&((*node) -> right), value);
    }
}

void traverse(Tree_Node *node) {
    if (node != NULL) {
        traverse(node -> left);
        printf("%d ", node -> value);
        traverse(node -> right);
    }
}

int main() {
    printf("Welcome to the Binary Search Tree program!\n");
    printf("Please enter the values you want to insert into the tree: (separated by spaces)\n");

    Tree_Node *root = NULL;
    char input[100];
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        int value = atoi(token);
        insert(&root, value);
        token = strtok(NULL, " ");
    }

    printf("Thank you! Here is the binary search tree in-order traversal:\n");
    traverse(root);

    return 0;
}