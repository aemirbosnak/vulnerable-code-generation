//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b) > 0;
}

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordFrequency *wordFrequencies = malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            word = strtok(token, ",.?!;:");

            if (word!= NULL) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }

                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Medieval Word Frequency Counter Results:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}