//LLAMA2-13B DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_DEPTH 5
#define MAX_LENGTH 1024

typedef struct node {
    char *word;
    int depth;
    struct node *prev;
    struct node *next;
} node_t;

node_t *create_node(char *word, int depth) {
    node_t *node = malloc(sizeof(node_t));
    node->word = word;
    node->depth = depth;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insert_node(node_t **head_ref, char *word) {
    node_t *new_node = create_node(word, 1);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
        new_node->prev = *head_ref;
        *head_ref = new_node;
    }
}

void print_node(node_t *node) {
    if (node != NULL) {
        printf("%s %d ", node->word, node->depth);
        print_node(node->next);
        print_node(node->prev);
    }
}

int main() {
    node_t *head = NULL;
    char word[MAX_LENGTH];
    int depth = 0;

    while (1) {
        printf("Enter a word: ");
        fgets(word, MAX_LENGTH, stdin);
        insert_node(&head, word);
        depth++;

        if (depth >= MAX_DEPTH) {
            break;
        }
    }

    print_node(head);

    return 0;
}