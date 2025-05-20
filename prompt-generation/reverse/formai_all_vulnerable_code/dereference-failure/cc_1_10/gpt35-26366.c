//FormAI DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct tree {
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *create_node(int val) {
    struct tree *node = malloc(sizeof(struct tree));
    node->value = val;
    node->left = node->right = NULL;
    printf("A new node has been born, value: %d\n", val);
    return node;
}

void insert_node(struct tree **root, int val) {
    if (*root == NULL) {
        *root = create_node(val);
        return;
    }
    if (val < (*root)->value) {
        printf("Going left...\n");
        insert_node(&(*root)->left, val);
    } else {
        printf("Going right...\n");
        insert_node(&(*root)->right, val);
    }
}

void traverse(struct tree *root) {
    if (root == NULL) {
        return;
    }
    printf("Traversing the tree, currently at value: %d\n", root->value);
    traverse(root->left);
    traverse(root->right);
}

int main() {
    struct tree *root = NULL;
    printf("Welcome to the surreal binary search tree.\n");
    printf("Enter some values to insert into the tree, separated by spaces. Press enter when done:\n");
    char input[100];
    fgets(input, 100, stdin);

    char *token;
    token = strtok(input, " ");
    while (token != NULL) {
        int val = atoi(token);
        insert_node(&root, val);
        token = strtok(NULL, " ");
    }

    printf("Finished inserting values. The tree just had a psychedelic trip, here's the order:\n");
    traverse(root);
    printf("The search is over, sending the tree to a higher dimension...\n");
    return 0;
}