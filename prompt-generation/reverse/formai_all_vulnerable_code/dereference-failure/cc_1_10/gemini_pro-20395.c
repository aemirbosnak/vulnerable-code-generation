//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
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
    new_node->next = head;
    head = new_node;
}

void increment_count(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    add_word(word);
}

void print_words() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_list() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *word = strtok(text, " ");
    while (word != NULL) {
        increment_count(word);
        word = strtok(NULL, " ");
    }

    print_words();
    free_list();

    return 0;
}