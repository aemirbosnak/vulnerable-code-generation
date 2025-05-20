//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_word(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node_t *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void print_words() {
    node_t *curr = head;
    while (curr != NULL) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }
}

int main() {
    char *text = "this is a sample text with some repeated words like this and a";

    char *token = strtok(text, " ");
    while (token != NULL) {
        add_word(token);
        token = strtok(NULL, " ");
    }

    print_words();

    return 0;
}