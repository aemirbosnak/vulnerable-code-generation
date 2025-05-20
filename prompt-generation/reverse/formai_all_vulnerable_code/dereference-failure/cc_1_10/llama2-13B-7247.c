//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_DEPTH 5

typedef struct node {
    char *str;
    int len;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(char *str, int len) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->str = str;
    node->len = len;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_node(node_t *node) {
    if (node == NULL) {
        printf("(NULL)\n");
        return;
    }

    printf("%s (%d)\n", node->str, node->len);

    print_node(node->left);
    print_node(node->right);
}

void recursive_print(node_t *root) {
    if (root == NULL) {
        return;
    }

    print_node(root);

    recursive_print(root->left);
    recursive_print(root->right);
}

int main() {
    node_t *root = NULL;

    root = create_node("Hello", 5);
    root->left = create_node("World", 4);
    root->right = create_node("!", 1);

    recursive_print(root);

    return 0;
}