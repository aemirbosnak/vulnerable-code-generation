//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_DEPTH 5

typedef struct node {
    char word[MAX_LEN];
    struct node *next;
    int depth;
} node_t;

node_t *search(node_t *root, char *word) {
    int len = strlen(word);
    node_t *current = root;
    int depth = 0;

    while (current != NULL && depth < MAX_DEPTH) {
        if (current->depth > depth) {
            break;
        }

        if (strcmp(current->word, word) == 0) {
            return current;
        }

        if (current->next == NULL) {
            break;
        }

        current = current->next;
        depth++;
    }

    return NULL;
}

int main() {
    node_t *root = NULL;

    root = (node_t *) malloc(sizeof(node_t));
    root->word[0] = 'A';
    root->word[1] = 'B';
    root->word[2] = 'C';
    root->next = NULL;
    root->depth = 0;

    node_t *node1 = (node_t *) malloc(sizeof(node_t));
    node1->word[0] = 'E';
    node1->word[1] = 'F';
    node1->word[2] = 'G';
    node1->next = NULL;
    node1->depth = 1;

    node_t *node2 = (node_t *) malloc(sizeof(node_t));
    node2->word[0] = 'G';
    node2->word[1] = 'H';
    node2->word[2] = 'I';
    node2->next = NULL;
    node2->depth = 2;

    node_t *node3 = (node_t *) malloc(sizeof(node_t));
    node3->word[0] = 'I';
    node3->word[1] = 'J';
    node3->word[2] = 'K';
    node3->next = NULL;
    node3->depth = 3;

    node_t *result = search(root, "G");

    if (result != NULL) {
        printf("Found %s at depth %d\n", result->word, result->depth);
    } else {
        printf("Not found\n");
    }

    return 0;
}