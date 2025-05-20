//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* w1 = a;
    const WordFrequency* w2 = b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE* inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency* wordFrequencies = malloc(MAX_NUM_WORDS * sizeof(WordFrequency));

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char* token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: maximum number of words exceeded.\n");
                return 1;
            }
            strcpy(wordFrequencies[numWords].word, token);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);
    return 0;
}