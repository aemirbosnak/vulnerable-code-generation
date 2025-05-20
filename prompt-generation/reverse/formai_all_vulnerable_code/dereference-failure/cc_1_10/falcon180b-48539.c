//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, char **words) {
    char word[MAX_WORD_LENGTH];
    int num_words = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }
}

void calculate_word_frequencies(char **words, int num_words, WordFrequency *word_frequencies) {
    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int frequency = 1;

        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(word, words[j]) == 0) {
                frequency++;
            }
        }

        strcpy(word_frequencies[i].word, word);
        word_frequencies[i].frequency = frequency;
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char **words = malloc(MAX_WORDS * sizeof(char *));
    int num_words = 0;

    read_file(file, words);
    fclose(file);

    WordFrequency *word_frequencies = malloc(MAX_WORDS * sizeof(WordFrequency));

    calculate_word_frequencies(words, num_words, word_frequencies);

    print_word_frequencies(word_frequencies, num_words);

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    for (int i = 0; i < num_words; i++) {
        free(word_frequencies[i].word);
    }
    free(word_frequencies);

    return 0;
}