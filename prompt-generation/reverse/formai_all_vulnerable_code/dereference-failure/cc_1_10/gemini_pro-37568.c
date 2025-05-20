//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
    char *word;
    int count;
};

struct word_list {
    struct word *words;
    int size;
    int capacity;
};

struct word_list *new_word_list() {
    struct word_list *list = malloc(sizeof(struct word_list));
    list->words = NULL;
    list->size = 0;
    list->capacity = 0;
    return list;
}

void add_word(struct word_list *list, char *word) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }
    list->words = realloc(list->words, sizeof(struct word) * (list->capacity + 1));
    list->words[list->capacity].word = strdup(word);
    list->words[list->capacity].count = 1;
    list->size++;
    list->capacity++;
}

void print_word_list(struct word_list *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

void free_word_list(struct word_list *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        free(list->words[i].word);
    }
    free(list->words);
    free(list);
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    struct word_list *list = new_word_list();
    char *token;
    token = strtok(text, " ");
    while (token != NULL) {
        add_word(list, token);
        token = strtok(NULL, " ");
    }
    print_word_list(list);
    free_word_list(list);
    return 0;
}