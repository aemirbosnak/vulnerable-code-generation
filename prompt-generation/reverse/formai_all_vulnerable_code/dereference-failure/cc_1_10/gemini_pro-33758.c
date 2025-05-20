//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100000

typedef struct node {
    char base;
    struct node *left;
    struct node *right;
} node;

node *new_node(char base) {
    node *n = malloc(sizeof(node));
    n->base = base;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert_node(node **root, char base) {
    if (*root == NULL) {
        *root = new_node(base);
        return;
    }

    if (base < (*root)->base) {
        insert_node(&(*root)->left, base);
    } else {
        insert_node(&(*root)->right, base);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%c", root->base);
    print_tree(root->right);
}

int main() {
    srand(time(NULL));

    char genome[MAX_STR_LEN];
    int genome_len = rand() % MAX_STR_LEN + 1;

    for (int i = 0; i < genome_len; i++) {
        genome[i] = rand() % 4 + 'A';
    }

    genome[genome_len] = '\0';

    node *root = NULL;

    for (int i = 0; i < genome_len; i++) {
        insert_node(&root, genome[i]);
    }

    print_tree(root);

    return 0;
}