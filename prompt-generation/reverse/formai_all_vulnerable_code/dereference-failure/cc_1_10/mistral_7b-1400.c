//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_NODE_NAME_LENGTH 20
#define MAX_TREE_HEIGHT 10

typedef struct Node {
    int key;
    char name[MAX_NODE_NAME_LENGTH];
    struct Node *left, *right;
} Node;

void generate_name(int key, char *name) {
    sprintf(name, "Node_%d", key);
}

Node *new_node(int key) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    generate_name(key, new_node->name);
    return new_node;
}

void insert(Node **root, int key) {
    if (*root == NULL) {
        *root = new_node(key);
        return;
    }

    if (key < (*root)->key)
        insert(&((*root)->left), key);
    else
        insert(&((*root)->right), key);
}

void print_node(Node *node) {
    printf("%s: %d\n", node->name, node->key);
}

void in_order_traversal_recursive(Node *node, int level) {
    if (node == NULL)
        return;

    in_order_traversal_recursive(node->left, level + 1);
    print_node(node);

    // Visualization
    if (level < MAX_TREE_HEIGHT) {
        for (int i = 0; i <= MAX_TREE_HEIGHT - level; i++)
            printf(" ");
        printf("-->%s:\n", node->name);
    }

    in_order_traversal_recursive(node->right, level + 1);
}

void display(Node *root) {
    printf("\nVisualization of the tree:\n");
    in_order_traversal_recursive(root, 0);
}

int main() {
    Node *root = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        insert(&root, rand() % 50);

    display(root);

    free(root);

    return 0;
}