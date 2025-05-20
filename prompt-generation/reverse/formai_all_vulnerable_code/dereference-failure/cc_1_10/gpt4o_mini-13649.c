//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(const char *text) {
    int inWord = 0;
    int wordCount = 0;
    
    while (*text) {
        if (isspace((unsigned char)*text)) {
            inWord = 0; // End of a word
        } else if (!inWord) {
            inWord = 1; // Beginning of a word
            wordCount++;
        }
        text++;
    }
    return wordCount;
}

// Function to interact with the plugin
void processInput(const char *input) {
    if (input == NULL) {
        fprintf(stderr, "No input provided!\n");
        return;
    }
    
    int wordCount = countWords(input);
    printf("Word Count: %d\n", wordCount);
}

// A simple example to demonstrate functionality
int main(int argc, char *argv[]) {
    // This simulates a scenario where the input comes from a web page
    if (argc < 2) {
        fprintf(stderr, "Usage: %s 'Your text here'\n", argv[0]);
        return 1;
    }

    // Combine all arguments into a single string
    size_t totalLength = 0;
    for (int i = 1; i < argc; ++i) {
        totalLength += strlen(argv[i]) + 1; // +1 for space or null terminator
    }

    char *fullText = malloc(totalLength);
    if (!fullText) {
        fprintf(stderr, "Memory allocation error!\n");
        return 1;
    }

    fullText[0] = '\0'; // Initialize the string

    for (int i = 1; i < argc; ++i) {
        strcat(fullText, argv[i]);
        if (i < argc - 1) {
            strcat(fullText, " "); // Add space between words
        }
    }

    // Process the combined input
    processInput(fullText);

    // Cleanup
    free(fullText);
    
    return 0;
}