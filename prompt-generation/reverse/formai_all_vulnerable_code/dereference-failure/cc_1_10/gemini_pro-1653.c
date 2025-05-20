//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *head = NULL;

void add_word(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void count_words(char *text) {
    char *word = strtok(text, " ");
    while (word != NULL) {
        add_word(word);
        word = strtok(NULL, " ");
    }
}

void print_words() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog.";

    count_words(text);
    print_words();

    return 0;
}