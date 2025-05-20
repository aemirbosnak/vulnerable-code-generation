//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: curious
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

int get_word_count(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void print_word_counts() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        add_word(token);
        token = strtok(NULL, " ");
    }

    // Print the word counts
    print_word_counts();

    return 0;
}