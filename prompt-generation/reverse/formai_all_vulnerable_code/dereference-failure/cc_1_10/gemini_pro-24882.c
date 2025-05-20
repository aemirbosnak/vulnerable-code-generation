//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *create_node(char *word) {
    node_t *node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    return node;
}

void add_word(node_t **head, char *word) {
    node_t *current = *head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    node_t *new_node = create_node(word);
    new_node->next = *head;
    *head = new_node;
}

void print_words(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    char *words = strtok(text, " ");
    node_t *head = NULL;
    while (words != NULL) {
        add_word(&head, words);
        words = strtok(NULL, " ");
    }
    print_words(head);
    return 0;
}