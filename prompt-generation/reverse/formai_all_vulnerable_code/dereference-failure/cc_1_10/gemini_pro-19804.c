//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add_word(const char *word) {
    node *new_node = malloc(sizeof(node));
    assert(new_node);

    new_node->word = strdup(word);
    assert(new_node->word);

    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void count_words(const char *text) {
    char *word = strtok(text, " ");
    while (word) {
        add_word(word);
        word = strtok(NULL, " ");
    }
}

void print_words() {
    node *current = head;
    while (current) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_list() {
    node *current = head;
    while (current) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    head = NULL;
    tail = NULL;
}

int main() {
    const char *text = "The quick brown fox jumped over the lazy dog.";
    count_words(text);
    print_words();
    free_list();
    return 0;
}