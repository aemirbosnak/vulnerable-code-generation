//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *inputFile;
    char inputBuffer[1024];
    char *word;
    struct WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(struct WordFrequency));
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
        word = strtok(inputBuffer, ",.?!;:");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            int wordLength = strlen(word);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Word too long: %s\n", word);
                exit(1);
            }

            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;

            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(struct WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}