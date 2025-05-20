//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t count;
    char *word;
} WordCount;

typedef struct {
    size_t size;
    WordCount *words;
} WordCountList;

WordCountList *create_word_count_list(void) {
    WordCountList *list = malloc(sizeof(WordCountList));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->words = NULL;

    return list;
}

void free_word_count_list(WordCountList *list) {
    if (list == NULL) {
        return;
    }

    for (size_t i = 0; i < list->size; i++) {
        free(list->words[i].word);
    }

    free(list->words);
    free(list);
}

int add_word_to_list(WordCountList *list, char *word) {
    if (list == NULL || word == NULL) {
        return -1;
    }

    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return 0;
        }
    }

    size_t new_size = list->size + 1;
    list->words = realloc(list->words, new_size * sizeof(WordCount));
    if (list->words == NULL) {
        return -1;
    }

    list->words[list->size].count = 1;
    list->words[list->size].word = strdup(word);
    if (list->words[list->size].word == NULL) {
        return -1;
    }

    list->size = new_size;

    return 0;
}

void print_word_count_list(WordCountList *list) {
    if (list == NULL) {
        return;
    }

    for (size_t i = 0; i < list->size; i++) {
        printf("%s: %ld\n", list->words[i].word, list->words[i].count);
    }
}

int main(int argc, char **argv) {
    WordCountList *list = create_word_count_list();
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        add_word_to_list(list, argv[i]);
    }

    print_word_count_list(list);

    free_word_count_list(list);

    return EXIT_SUCCESS;
}