//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *string) {
    // Initialize the word count
    int wordCount = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(string); i++) {
        // If the current character is a space, then we have reached the end of a word
        if (string[i] == ' ') {
            // Increment the word count
            wordCount++;
        }
    }

    // Return the word count
    return wordCount;
}

// Function to count the number of characters in a string
int countCharacters(char *string) {
    // Initialize the character count
    int characterCount = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(string); i++) {
        // If the current character is not a space, then we have reached the end of a character
        if (string[i] != ' ') {
            // Increment the character count
            characterCount++;
        }
    }

    // Return the character count
    return characterCount;
}

// Function to count the number of lines in a string
int countLines(char *string) {
    // Initialize the line count
    int lineCount = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(string); i++) {
        // If the current character is a newline, then we have reached the end of a line
        if (string[i] == '\n') {
            // Increment the line count
            lineCount++;
        }
    }

    // Return the line count
    return lineCount;
}

// Main function
int main() {
    // Get the input string from the user
    char *string = malloc(100);
    printf("Enter the string: ");
    gets(string);

    // Count the number of words, characters, and lines in the string
    int wordCount = countWords(string);
    int characterCount = countCharacters(string);
    int lineCount = countLines(string);

    // Print the word count, character count, and line count
    printf("The number of words in the string is: %d\n", wordCount);
    printf("The number of characters in the string is: %d\n", characterCount);
    printf("The number of lines in the string is: %d\n", lineCount);

    // Free the allocated memory
    free(string);

    return 0;
}