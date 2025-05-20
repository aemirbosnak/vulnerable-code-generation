//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char *word;
    struct node *next;
    int depth;
} node_t;

node_t *build_trie(char *text) {
    node_t *root = NULL;
    char *word = NULL;
    int depth = 0;

    while ((word = strtok(text, " ")) != NULL) {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->word = word;
        new_node->next = root;
        new_node->depth = depth;
        root = new_node;
        depth++;
    }

    return root;
}

void print_trie(node_t *root) {
    char *word = NULL;
    int depth = 0;

    while (root != NULL) {
        printf("%s%c", root->word, (root->depth == depth) ? ' ' : '\n');
        depth++;
        root = root->next;
    }
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog";
    node_t *trie = build_trie(text);
    print_trie(trie);

    return 0;
}