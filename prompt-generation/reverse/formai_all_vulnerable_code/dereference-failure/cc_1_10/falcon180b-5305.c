//Falcon-180B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void addWord(char* word, WordFrequency* wordFrequencies, int numWords, int* numWordsPtr) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            wordFrequencies[i].frequency++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(wordFrequencies[numWords].word, word);
    wordFrequencies[numWords].frequency = 1;
    numWords++;
    *numWordsPtr = numWords;
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    char inputFile[100];
    char outputFile[100];
    FILE* input;
    FILE* output;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    while (fscanf(input, "%s", word)!= EOF) {
        addWord(word, wordFrequencies, numWords, &numWords);
    }

    fclose(input);
    fclose(output);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}