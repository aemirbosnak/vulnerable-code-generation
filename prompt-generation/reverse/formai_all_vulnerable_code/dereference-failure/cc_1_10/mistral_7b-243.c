//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

void count_words(char *str, int *word_count, int *words[]) {
    int i = 0, word_index = 0, word_len = 0;
    char word[WORD_LENGTH];

    for (; *str != '\0'; str++) {
        if (isspace(*str)) {
            if (word_len > 0) {
                words[word_index++] = malloc(word_len * sizeof(char));
                strncpy(words[word_index - 1], word, word_len);
                words[word_index - 1][word_len] = '\0';
                word_len = 0;
                (*word_count)++;
            }
            continue;
        }

        word[word_len++] = *str;
    }

    if (word_len > 0) {
        words[word_index++] = malloc(word_len * sizeof(char));
        strncpy(words[word_index - 1], word, word_len);
        words[word_index - 1][word_len] = '\0';
        (*word_count)++;
    }

    words[word_index] = NULL;
}

int main(int argc, char *argv[]) {
    int word_count = 0, i = 0;
    int *words = malloc(MAX_WORDS * sizeof(int*));

    if (argc > 1) {
        char *input = argv[1];
        count_words(input, &word_count, words);
        printf("Word count: %d\n", word_count);

        for (; words[i] != NULL; i++) {
            printf("%s ", words[i]);
            free(words[i]);
        }

        free(words);
    }

    return 0;
}