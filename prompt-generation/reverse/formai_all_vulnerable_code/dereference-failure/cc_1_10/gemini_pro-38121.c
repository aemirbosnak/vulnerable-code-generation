//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
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
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }

        current = current->next;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void print_words() {
    node_t *current = head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    char *p = strtok(text, " ");

    while (p != NULL) {
        add_word(p);
        p = strtok(NULL, " ");
    }

    print_words();

    return 0;
}