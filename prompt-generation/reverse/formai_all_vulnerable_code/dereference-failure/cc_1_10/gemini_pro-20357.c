//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
} node_t;

node_t *new_node(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_word(node_t **root, char *word) {
    if (*root == NULL) {
        *root = new_node(word);
        return;
    }

    int cmp = strcmp(word, (*root)->word);
    if (cmp < 0) {
        insert_word(&(*root)->left, word);
    } else if (cmp > 0) {
        insert_word(&(*root)->right, word);
    } else {
        (*root)->count++;
    }
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%s: %d\n", root->word, root->count);
    print_tree(root->right);
}

void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->word);
    free(root);
}

int main() {
    node_t *root = NULL;

    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++) {
        insert_word(&root, words[i]);
    }

    print_tree(root);

    free_tree(root);

    return 0;
}