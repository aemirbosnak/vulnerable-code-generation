//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Word {
    char* word;
    int count;
};

struct WordList {
    struct Word* words;
    int size;
    int capacity;
};

void init_word_list(struct WordList* wl) {
    wl->words = NULL;
    wl->size = 0;
    wl->capacity = 0;
}

void add_word(struct WordList* wl, char* word) {
    if (wl->size >= wl->capacity) {
        wl->capacity = wl->capacity ? wl->capacity * 2 : 16;
        wl->words = realloc(wl->words, wl->capacity * sizeof(struct Word));
    }

    int i;
    for (i = 0; i < wl->size; i++) {
        if (!strcmp(word, wl->words[i].word)) {
            wl->words[i].count++;
            return;
        }
    }

    wl->words[wl->size].word = strdup(word);
    wl->words[wl->size].count = 1;
    wl->size++;
}

void free_word_list(struct WordList* wl) {
    for (int i = 0; i < wl->size; i++) {
        free(wl->words[i].word);
    }
    free(wl->words);
}

void print_word_list(struct WordList* wl) {
    for (int i = 0; i < wl->size; i++) {
        printf("%s: %d\n", wl->words[i].word, wl->words[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct WordList wl;
    init_word_list(&wl);

    char word[256];
    while (fscanf(fp, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        add_word(&wl, word);
    }

    fclose(fp);

    print_word_list(&wl);

    free_word_list(&wl);

    return EXIT_SUCCESS;
}