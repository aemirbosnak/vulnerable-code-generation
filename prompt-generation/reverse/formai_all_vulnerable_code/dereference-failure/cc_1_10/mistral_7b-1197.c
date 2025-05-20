//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word {
    char *word;
    int count;
} Word;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int word_capacity = 100;
    Word *words = malloc(word_capacity * sizeof(Word));
    int num_words = 0;

    char word_buffer[1024];
    while (fgets(word_buffer, sizeof(word_buffer), file)) {
        int i;
        for (i = 0; i < num_words; ++i) {
            if (strcmp(words[i].word, word_buffer) == 0) {
                ++words[i].count;
                break;
            }
        }

        if (i == num_words) {
            if (num_words == word_capacity) {
                word_capacity *= 2;
                words = realloc(words, word_capacity * sizeof(Word));
            }

            words[num_words].word = strdup(word_buffer);
            words[num_words].count = 1;
            ++num_words;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    free(words);

    return 0;
}