//FormAI DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the summary length
#define SUMMARY_LENGTH 10

// Define a struct for the Word frequency
typedef struct WordFrequency {
    char word[100];
    int count;
} WordFrequency;

// Main function
int main() {
    char input[1000]; // Input text
    int wordCount = 0; // Total number of words in the text
    int uniqueWords = 0; // Total number of unique words in the text
    WordFrequency *wordFreq = malloc(sizeof(WordFrequency) * 1000); // Array to store the word frequencies
    
    // Get the text input
    printf("Enter the text to summarize:\n");
    fgets(input, 1000, stdin);
    
    // Tokenize the text into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Check if the word already exists in wordFreq array
        int exists = 0;
        for (int i = 0; i < uniqueWords; i++) {
            if (strcmp(token, wordFreq[i].word) == 0) {
                // If the word exists, increment the count
                wordFreq[i].count++;
                exists = 1;
                break;
            }
        }
        
        // If the word does not exists, add it to wordFreq array
        if (!exists) {
            strncpy(wordFreq[uniqueWords].word, token, 100);
            wordFreq[uniqueWords].count = 1;
            uniqueWords++;
        }
        
        wordCount++;
        token = strtok(NULL, " ");
    }
    
    // Sort the wordFreq array in descending order of frequency
    for (int i = 0; i < uniqueWords - 1; i++) {
        for (int j = i + 1; j < uniqueWords; j++) {
            if (wordFreq[j].count > wordFreq[i].count) {
                WordFrequency temp = wordFreq[i];
                wordFreq[i] = wordFreq[j];
                wordFreq[j] = temp;
            }
        }
    }
    
    // Get the top SUMMARY_LENGTH words
    printf("Summary:\n");
    int i = 0;
    while (i < SUMMARY_LENGTH && i < uniqueWords) {
        printf("%s ", wordFreq[i].word);
        i++;
    }
    
    // Free the memory allocated to wordFreq array
    free(wordFreq);
    
    return 0;
}