//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word frequency
typedef struct {
    char* word;
    int count;
} WordFrequency;

// Function to compare two WordFrequency structures
int compareWordFrequency(const void* a, const void* b) {
    WordFrequency* wa = (WordFrequency*)a;
    WordFrequency* wb = (WordFrequency*)b;
    return strcmp(wa->word, wb->word);
}

// Function to count the words in a string
int countWords(char* text) {
    int wordCount = 0;
    char* word = strtok(text, " ");
    while (word != NULL) {
        wordCount++;
        word = strtok(NULL, " ");
    }
    return wordCount;
}

// Function to create an array of WordFrequency structures
WordFrequency* createWordFrequencyArray(char* text) {
    // Count the number of words in the text
    int wordCount = countWords(text);

    // Create an array of WordFrequency structures
    WordFrequency* wordFrequencyArray = (WordFrequency*)malloc(sizeof(WordFrequency) * wordCount);

    // Tokenize the text and count the frequency of each word
    char* word = strtok(text, " ");
    int i = 0;
    while (word != NULL) {
        wordFrequencyArray[i].word = word;
        wordFrequencyArray[i].count = 0;
        word = strtok(NULL, " ");
        i++;
    }

    // Sort the array of WordFrequency structures alphabetically
    qsort(wordFrequencyArray, wordCount, sizeof(WordFrequency), compareWordFrequency);

    // Count the frequency of each word
    for (i = 0; i < wordCount; i++) {
        char* word = wordFrequencyArray[i].word;
        int count = 0;
        char* found = strstr(text, word);
        while (found != NULL) {
            count++;
            found = strstr(found + 1, word);
        }
        wordFrequencyArray[i].count = count;
    }

    return wordFrequencyArray;
}

// Function to print the word frequency array
void printWordFrequencyArray(WordFrequency* wordFrequencyArray, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencyArray[i].word, wordFrequencyArray[i].count);
    }
}

// Function to free the memory allocated for the word frequency array
void freeWordFrequencyArray(WordFrequency* wordFrequencyArray, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        free(wordFrequencyArray[i].word);
    }
    free(wordFrequencyArray);
}

// Main function
int main() {
    // Get the text from the user
    char* text = malloc(1000);
    printf("Enter the text: ");
    gets(text);

    // Create an array of WordFrequency structures
    WordFrequency* wordFrequencyArray = createWordFrequencyArray(text);

    // Get the number of words in the text
    int wordCount = countWords(text);

    // Print the word frequency array
    printWordFrequencyArray(wordFrequencyArray, wordCount);

    // Free the memory allocated for the word frequency array
    freeWordFrequencyArray(wordFrequencyArray, wordCount);

    // Free the memory allocated for the text
    free(text);

    return 0;
}