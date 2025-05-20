//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *new_node(char *word, int count) {
    Node *node = malloc(sizeof(Node));
    node->word = strdup(word);
    node->count = count;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert_node(Node *root, char *word, int count) {
    if (root == NULL) {
        return new_node(word, count);
    }
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insert_node(root->left, word, count);
    } else if (cmp > 0) {
        root->right = insert_node(root->right, word, count);
    } else {
        root->count += count;
    }
    return root;
}

void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%s: %d\n", root->word, root->count);
    print_tree(root->left);
    print_tree(root->right);
}

void free_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    free(root->word);
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;

    char *words[] = {
        "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"
    };

    for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
        root = insert_node(root, words[i], 1);
    }

    print_tree(root);

    free_tree(root);

    return 0;
}