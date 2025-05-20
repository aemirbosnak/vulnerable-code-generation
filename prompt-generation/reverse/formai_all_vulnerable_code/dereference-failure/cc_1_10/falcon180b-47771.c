//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(FILE *file, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }
}

void countWordFrequencies(char words[MAX_WORDS][MAX_WORD_LENGTH], int frequencies[MAX_WORDS]) {
    int i, j;

    for (i = 0; i < MAX_WORDS; i++) {
        frequencies[i] = 0;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
                break;
            }
        }
    }
}

void printWordFrequencies(WordFrequency frequencies[MAX_WORDS], int numWords) {
    qsort(frequencies, numWords, sizeof(WordFrequency), compareStrings);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];

    readWords(inputFile, words);
    countWordFrequencies(words, frequencies);
    printWordFrequencies(frequencies, MAX_WORDS);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].count > 0) {
            fprintf(outputFile, "%s: %d\n", frequencies[i].word, frequencies[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}