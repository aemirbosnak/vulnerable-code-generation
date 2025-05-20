//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000000
#define MAX_CHILDREN 10000

typedef struct node {
    char *word;
    int count;
    int is_end_of_word;
    struct node *children[MAX_CHILDREN];
} node_t;

node_t *root = NULL;

void insert(node_t *node, char *word) {
    int len = strlen(word);
    if (len == 0) {
        node->is_end_of_word = 1;
    } else {
        node->children[word[0]] = (node_t *)malloc(sizeof(node_t));
        node = node->children[word[0]];
        insert(node, word + 1);
    }
}

void delete(node_t *node) {
    if (node->is_end_of_word) {
        node->is_end_of_word = 0;
        node->count = 0;
    } else if (node->count == 0) {
        for (int i = 0; i < MAX_CHILDREN; i++) {
            if (node->children[i]!= NULL) {
                delete(node->children[i]);
                node->children[i] = NULL;
            }
        }
        free(node);
        node = NULL;
    }
}

void search(node_t *node, char *word) {
    int len = strlen(word);
    if (len == 0) {
        if (node->is_end_of_word) {
            printf("%s: %d\n", word, node->count);
        }
    } else {
        char ch = word[0];
        node_t *child = node->children[ch];
        if (child!= NULL) {
            search(child, word + 1);
        }
    }
}

int main() {
    root = (node_t *)malloc(sizeof(node_t));
    memset(root, 0, sizeof(node_t));

    char word[100];
    while (fscanf(stdin, "%s", word)!= EOF) {
        insert(root, word);
    }

    char search_word[100];
    while (fscanf(stdin, "%s", search_word)!= EOF) {
        search(root, search_word);
    }

    delete(root);
    return 0;
}