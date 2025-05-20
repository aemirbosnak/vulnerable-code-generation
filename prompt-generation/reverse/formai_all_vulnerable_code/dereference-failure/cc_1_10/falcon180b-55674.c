//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char *word;
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    if ((file = fopen("input.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, 1000, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words (max %d).\n", MAX_WORDS);
                exit(1);
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}