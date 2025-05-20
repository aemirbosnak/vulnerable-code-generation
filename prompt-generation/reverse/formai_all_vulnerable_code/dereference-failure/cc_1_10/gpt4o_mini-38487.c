//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void initializeWordFreqArray(WordFreq *wordFreqArray, int size) {
    for (int i = 0; i < size; i++) {
        wordFreqArray[i].count = 0;
        wordFreqArray[i].word[0] = '\0';
    }
}

int addOrUpdateWord(WordFreq *wordFreqArray, int size, const char *newWord) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordFreqArray[i].word, newWord) == 0) {
            wordFreqArray[i].count++;
            return size; // Word exists already, return the same size
        }
        if (wordFreqArray[i].count == 0) {
            // Found an empty spot
            strncpy(wordFreqArray[i].word, newWord, MAX_WORD_LENGTH);
            wordFreqArray[i].count = 1;
            return size + 1; // Increased size
        }
    }
    return size; // No space left
}

void printWordFrequencies(WordFreq *wordFreqArray, int size) {
    printf("\n\nWonderful word frequencies:\n");
    for (int i = 0; i < size; i++) {
        if (wordFreqArray[i].count > 0) {
            printf("%s: %d\n", wordFreqArray[i].word, wordFreqArray[i].count);
        }
    }
}

void cleanUp(WordFreq *wordFreqArray) {
    free(wordFreqArray);
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    WordFreq *wordFreqArray = malloc(MAX_WORDS * sizeof(WordFreq));
    initializeWordFreqArray(wordFreqArray, MAX_WORDS);

    file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }

    printf("Hip Hip Hooray! Let's start analyzing the text data!\n");

    while (fscanf(file, "%49s", word) == 1) {
        wordCount = addOrUpdateWord(wordFreqArray, wordCount, word);
    }

    fclose(file);
    
    printWordFrequencies(wordFreqArray, wordCount);
    
    cleanUp(wordFreqArray);
    
    printf("\nData mining complete! Have a cheerful day ahead!\n");
    
    return EXIT_SUCCESS;
}