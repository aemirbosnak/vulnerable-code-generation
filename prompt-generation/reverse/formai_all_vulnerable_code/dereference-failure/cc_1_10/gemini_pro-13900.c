//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node;

typedef struct word_list {
    word_node *head;
    word_node *tail;
    int size;
} word_list;

word_list *create_word_list() {
    word_list *list = malloc(sizeof(word_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_word_to_list(word_list *list, char *word) {
    word_node *new_node = malloc(sizeof(word_node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void increase_word_count(word_list *list, char *word) {
    word_node *current_node = list->head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            current_node->count++;
            return;
        }
        current_node = current_node->next;
    }

    add_word_to_list(list, word);
}

void print_word_list(word_list *list) {
    word_node *current_node = list->head;

    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

void free_word_list(word_list *list) {
    word_node *current_node = list->head;

    while (current_node != NULL) {
        word_node *next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    free(list);
}

int main() {
    char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";
    char *delimiters = " ,.-;:\n\t";

    word_list *list = create_word_list();

    char *token = strtok(text, delimiters);
    while (token != NULL) {
        increase_word_count(list, token);
        token = strtok(NULL, delimiters);
    }

    print_word_list(list);

    free_word_list(list);

    return 0;
}