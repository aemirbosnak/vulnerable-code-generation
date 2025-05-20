//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = head;
    head = new_node;
}

void count(char *word) {
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    insert(word);
}

void print() {
    node_t *current = head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *token = strtok(text, " ");

    while (token != NULL) {
        count(token);
        token = strtok(NULL, " ");
    }

    print();

    return 0;
}