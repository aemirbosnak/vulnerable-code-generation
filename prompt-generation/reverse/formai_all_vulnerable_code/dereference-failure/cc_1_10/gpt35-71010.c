//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count word frequency
void countFrequency(char* text) {
    // Initialize variables
    int i, j, count, freq = 0;

    // Convert the text to lowercase
    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // Tokenize the text into words
    char* token = strtok(text, " ");

    // Create array to store unique words and their frequency
    char** words = (char**) malloc(sizeof(char*) * strlen(text));
    int* frequency = (int*) malloc(sizeof(int) * strlen(text));
    int numWords = 0;

    // Loop through each word
    while (token != NULL) {
        // Check if word is already in words array
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i]) == 0) {
                frequency[i]++;
                freq = 1;
                break;
            }
        }

        // If word is not in words array, add it
        if (freq == 0) {    
            words[numWords] = token;
            frequency[numWords] = 1;
            numWords++;
        }

        // Reset frequency for next iteration
        freq = 0;

        // Get next word
        token = strtok(NULL, " ");
    }

    // Print word frequency table
    printf("Word Frequency Table:\n");
    printf("=====================\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    // Free memory
    free(words);
    free(frequency);
}

// Main function
int main() {
    // Input text
    char text[1000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from text
    text[strcspn(text, "\n")] = 0;

    // Call function to count word frequency
    countFrequency(text);

    return 0;
}