//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            WordFrequency *foundWord = bsearch(word, wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
            if (foundWord == NULL) {
                foundWord = realloc(wordFrequencies, (numWords + 1) * sizeof(WordFrequency));
                if (foundWord == NULL) {
                    printf("Error: Could not allocate memory for word frequencies.\n");
                    exit(1);
                }
                strcpy(foundWord[numWords].word, word);
                foundWord[numWords].count = 1;
                wordFrequencies = foundWord;
            } else {
                foundWord->count++;
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    // Sort word frequencies by count
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    // Free memory
    free(wordFrequencies);
    fclose(inputFile);
    return 0;
}