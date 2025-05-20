//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWordFrequency(const void *a, const void *b) {
    const WordFrequency *wa = (const WordFrequency *)a;
    const WordFrequency *wb = (const WordFrequency *)b;
    return strcmp(wa->word, wb->word);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int words = 0;
    int capacity = 1000;
    WordFrequency *wordFrequency = malloc(sizeof(WordFrequency) * capacity);
    if (wordFrequency == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *word = strtok(buffer, " \t\r\n");
        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < words; i++) {
                if (strcmp(word, wordFrequency[i].word) == 0) {
                    wordFrequency[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (words >= capacity) {
                    capacity *= 2;
                    wordFrequency = realloc(wordFrequency, sizeof(WordFrequency) * capacity);
                    if (wordFrequency == NULL) {
                        perror("realloc");
                        return EXIT_FAILURE;
                    }
                }
                wordFrequency[words].word = strdup(word);
                wordFrequency[words].count = 1;
                words++;
            }
            word = strtok(NULL, " \t\r\n");
        }
    }

    fclose(file);

    qsort(wordFrequency, words, sizeof(WordFrequency), compareWordFrequency);

    for (int i = 0; i < words; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }

    for (int i = 0; i < words; i++) {
        free(wordFrequency[i].word);
    }
    free(wordFrequency);

    return EXIT_SUCCESS;
}