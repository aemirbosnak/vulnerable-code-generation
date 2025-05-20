//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words) {
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer)!= EOF) {
        strcpy(words->word, buffer);
        words->count = 1;
        words++;
    }
}

void countWords(WordFrequency *words, int numWords) {
    WordFrequency *currentWord = words;
    while (numWords-- > 0) {
        currentWord->count++;
        currentWord++;
    }
}

void printWords(WordFrequency *words, int numWords) {
    WordFrequency *currentWord = words;
    while (numWords-- > 0) {
        printf("%s %d\n", currentWord->word, currentWord->count);
        currentWord++;
    }
}

int main() {
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    WordFrequency *words = malloc(sizeof(WordFrequency) * MAX_WORDS);
    if (words == NULL) {
        printf("Error allocating memory for word frequencies.\n");
        exit(1);
    }

    readWords(inputFile, words);
    countWords(words, MAX_WORDS);
    printWords(words, MAX_WORDS);

    free(words);
    fclose(inputFile);

    return 0;
}