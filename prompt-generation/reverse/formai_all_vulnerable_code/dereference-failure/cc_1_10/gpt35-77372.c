//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// Struct to store word and frequency pair
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequencyPair;

// Function to parse words from input string and return a list of unique words
WordFrequencyPair* getUniqueWords(char* input, int* numUniqueWords) {
    // Split input string into words
    char* word = strtok(input, " \t\n");
    WordFrequencyPair* wordFrequencyPairs = NULL;
    int numWords = 0;
    // Loop through each word and add to list of unique words
    while (word != NULL) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // Check if word is already in list of unique words
        int wordIndex = -1;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, wordFrequencyPairs[i].word) == 0) {
                wordIndex = i;
                break;
            }
        }
        // If word is not in list of unique words, add it
        if (wordIndex == -1) {
            numWords++;
            wordFrequencyPairs = realloc(wordFrequencyPairs, numWords * sizeof(WordFrequencyPair));
            strcpy(wordFrequencyPairs[numWords-1].word, word);
            wordFrequencyPairs[numWords-1].frequency = 1;
        }
        // If word is in list of unique words, increment frequency
        else {
            wordFrequencyPairs[wordIndex].frequency++;
        }
        // Get next word
        word = strtok(NULL, " \t\n");
    }
    // Set output parameters and return list of unique words
    *numUniqueWords = numWords;
    return wordFrequencyPairs;
}

int main() {
    // Get input text from user
    printf("Enter text: ");
    char input[10000];
    fgets(input, sizeof(input), stdin);
    // Get list of unique words with frequencies
    int numUniqueWords;
    WordFrequencyPair* wordFrequencyPairs = getUniqueWords(input, &numUniqueWords);
    // Sort list of unique words by frequency in descending order
    for (int i = 0; i < numUniqueWords-1; i++) {
        for (int j = i+1; j < numUniqueWords; j++) {
            if (wordFrequencyPairs[i].frequency < wordFrequencyPairs[j].frequency) {
                WordFrequencyPair temp = wordFrequencyPairs[i];
                wordFrequencyPairs[i] = wordFrequencyPairs[j];
                wordFrequencyPairs[j] = temp;
            }
        }
    }
    // Print out list of unique words with frequencies
    printf("Word\t\tFrequency\n");
    printf("======================\n");
    for (int i = 0; i < numUniqueWords; i++) {
        printf("%s\t\t%d\n", wordFrequencyPairs[i].word, wordFrequencyPairs[i].frequency);
    }
    // Free memory allocated for list of unique words
    free(wordFrequencyPairs);
    return 0;
}