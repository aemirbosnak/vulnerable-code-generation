//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int numWords = 0;
    WordFrequency* wordFrequencies = (WordFrequency*)malloc(MAX_WORDS * sizeof(WordFrequency));

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        WordFrequency* wordFrequency = (WordFrequency*)malloc(sizeof(WordFrequency));
        strcpy(wordFrequency->word, word);
        wordFrequency->frequency = 1;

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                free(wordFrequency);
                break;
            }
        }

        if (i == numWords) {
            wordFrequencies[numWords] = *wordFrequency;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}