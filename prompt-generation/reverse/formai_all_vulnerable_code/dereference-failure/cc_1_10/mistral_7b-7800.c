//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
#define WORD_COUNT_SIZE (MAX_WORDS * sizeof(int))

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void _count_words(char *str, Word *words, int *num_words) {
    int i = 0, j = 0, word_len = 0;
    int num_words_local = *num_words;

    if (words == NULL || num_words == NULL) {
        fprintf(stderr, "Invalid arguments.\n");
        exit(EXIT_FAILURE);
    }

    while (*str != '\0') {
        while (isspace(*str)) str++;

        if (*str == '\0') break;

        word_len = 0;
        while (!isspace(*(str + word_len)) && (*(str + word_len) != '\0')) {
            if (num_words_local >= MAX_WORDS) {
                fprintf(stderr, "Too many words.\n");
                exit(EXIT_FAILURE);
            }

            words[num_words_local].word[word_len] = *(str + word_len);
            word_len++;
            str++;
        }

        words[num_words_local].word[word_len] = '\0';
        words[num_words_local].count = 1;

        num_words_local++;

        while (isspace(*str)) str++;
    }

    *num_words = num_words_local;
}

void _increment_count(Word *words, int num_words, int index) {
    if (index >= 0 && index < num_words) {
        words[index].count++;
    }
}

int main(int argc, char *argv[]) {
    int num_words = 0;
    Word *words = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    words = (Word *)calloc(MAX_WORDS, sizeof(Word));
    if (words == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    _count_words(argv[1], words, &num_words);

    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, argv[i]) == 0) {
                _increment_count(words, num_words, j);
                break;
            }
        }
    }

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);

    return EXIT_SUCCESS;
}