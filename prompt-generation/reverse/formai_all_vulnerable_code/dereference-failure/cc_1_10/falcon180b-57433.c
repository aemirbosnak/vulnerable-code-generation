//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 10
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;
    return strcmp(wordA->word, wordB->word);
}

void printFrequencyTable(WordFrequency *wordFrequencies, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        WordFrequency *word = &wordFrequencies[i];
        printf("%s\t%d\n", word->word, word->count);
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    WordFrequency *wordFrequencies;
    int numWords = 0;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    // Allocate memory for the word frequency table
    wordFrequencies = (WordFrequency *) malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    if (wordFrequencies == NULL) {
        printf("Error: could not allocate memory for word frequency table\n");
        return 1;
    }

    // Read the input file and count the frequency of each word
    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        WordFrequency *word = &wordFrequencies[numWords];
        strcpy(word->word, inputBuffer);
        word->count = 1;
        numWords++;

        // Sort the word frequency table by word
        qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    }

    // Print the word frequency table
    printFrequencyTable(wordFrequencies, numWords);

    // Close the input file
    fclose(inputFile);

    // Free the memory allocated for the word frequency table
    free(wordFrequencies);

    return 0;
}