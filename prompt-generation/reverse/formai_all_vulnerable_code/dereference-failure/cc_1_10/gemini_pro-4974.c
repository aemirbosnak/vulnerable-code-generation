//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node_t;

typedef struct word_list {
    word_node_t *head;
    word_node_t *tail;
    int size;
} word_list_t;

word_list_t *create_word_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_word_to_list(word_list_t *list, char *word) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
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

int find_word_in_list(word_list_t *list, char *word) {
    word_node_t *current_node = list->head;
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node->count;
        }
        current_node = current_node->next;
    }
    return 0;
}

void print_word_list(word_list_t *list) {
    word_node_t *current_node = list->head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

void free_word_list(word_list_t *list) {
    word_node_t *current_node = list->head;
    while (current_node != NULL) {
        word_node_t *next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int main() {
    word_list_t *word_list = create_word_list();

    // Read words from standard input and add them to the word list.
    char word[1024];
    while (scanf("%s", word) != EOF) {
        add_word_to_list(word_list, word);
    }

    // Print the word list.
    print_word_list(word_list);

    // Free the word list.
    free_word_list(word_list);

    return 0;
}