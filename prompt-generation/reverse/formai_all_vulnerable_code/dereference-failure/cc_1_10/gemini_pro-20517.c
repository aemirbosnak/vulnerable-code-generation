//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <assert.h>
#include <ctype.h>
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
    int size;
} word_list_t;

word_list_t *create_word_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroy_word_list(word_list_t *list) {
    word_node_t *current = list->head;
    while (current != NULL) {
        word_node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    free(list);
}

int compare_words(const void *a, const void *b) {
    const char *word1 = ((word_node_t *)a)->word;
    const char *word2 = ((word_node_t *)b)->word;
    return strcmp(word1, word2);
}

void add_word_to_list(word_list_t *list, char *word) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        word_node_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
}

void increment_word_count(word_list_t *list, char *word) {
    word_node_t *current = list->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            break;
        }
        current = current->next;
    }
}

void print_word_list(word_list_t *list) {
    word_node_t *current = list->head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    word_list_t *list = create_word_list();

    char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (char *c = token; *c != '\0'; c++) {
            *c = tolower(*c);
        }
        add_word_to_list(list, token);
        token = strtok(NULL, " ");
    }

    qsort(list->head, list->size, sizeof(word_node_t), compare_words);

    print_word_list(list);

    destroy_word_list(list);

    return 0;
}