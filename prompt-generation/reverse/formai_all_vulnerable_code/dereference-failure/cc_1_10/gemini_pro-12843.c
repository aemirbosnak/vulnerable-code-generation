//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
    char *word;
    int count;
    struct _node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add_word(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
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

void print_words() {
    node *current_node = head;
    while (current_node) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

int main() {
    char *input = "Hello world! This is a sample text. This is a sample text. This is a sample text.";
    char *word;

    char *token = strtok(input, " ");
    while (token) {
        add_word(token);
        token = strtok(NULL, " ");
    }

    print_words();

    return 0;
}