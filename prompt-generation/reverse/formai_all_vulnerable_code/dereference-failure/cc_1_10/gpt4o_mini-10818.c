//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold word and frequency
typedef struct {
    char word[50];
    int count;
} WordFrequency;

// Function to find a word in the list
int findWord(WordFrequency *arr, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].word, word) == 0) {
            return i; // Word found
        }
    }
    return -1; // Word not found
}

// Function to print the word frequencies
void printFrequencies(WordFrequency *arr, int size) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].word, arr[i].count);
    }
}

int main() {
    // Buffer for reading words
    char buffer[1000];
    printf("Enter text (type 'exit' on a new line to finish):\n");
    
    // Dynamic array for storing word frequencies
    int maxSize = 10;
    WordFrequency *wordFrequencies = (WordFrequency *)malloc(maxSize * sizeof(WordFrequency));
    int size = 0;

    while (1) {
        // Read a line of input
        fgets(buffer, sizeof(buffer), stdin);
        
        // Check if 'exit' was entered
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        // Tokenizing the input to get words
        char *word = strtok(buffer, " \n");
        while (word != NULL) {
            int index = findWord(wordFrequencies, size, word);
            if (index != -1) {
                // Word found, increment the count
                wordFrequencies[index].count++;
            } else {
                // Word not found, add it
                if (size >= maxSize) {
                    maxSize *= 2;
                    wordFrequencies = (WordFrequency *)realloc(wordFrequencies, maxSize * sizeof(WordFrequency));
                }
                strcpy(wordFrequencies[size].word, word);
                wordFrequencies[size].count = 1;
                size++;
            }
            word = strtok(NULL, " \n");
        }
    }

    // Print the results
    printFrequencies(wordFrequencies, size);

    // Free the allocated memory
    free(wordFrequencies);
    
    return 0;
}