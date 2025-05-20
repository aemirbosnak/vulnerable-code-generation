//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to count words in a given string
int countWords(const char *str) {
    int state = 0;
    int wordCount = 0;

    while (*str) {
        // If we encounter a space or newline, we set state to OUT
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            state = 0;
        } else if (state == 0) {
            // We found a new word
            state = 1;
            wordCount++;
        }
        str++;
    }

    return wordCount;
}

// Function to read file and count words
int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return -1;
    }

    char *buffer = NULL;
    size_t size = 0;
    int totalWords = 0;

    // Read the file line by line
    while (getline(&buffer, &size, file) != -1) {
        totalWords += countWords(buffer);
    }

    free(buffer);
    fclose(file);
    return totalWords;
}

// Function to provide a simple user prompt
void displayUsage() {
    printf("Word Count Tool\n");
    printf("Usage: ./word_count <filename>\n");
    printf("Counts the number of words in the specified file.\n");
}

// Main function to control program flow
int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int wordCount = countWordsInFile(filename);

    if (wordCount == -1) {
        return EXIT_FAILURE; // Error already printed in countWordsInFile
    }

    printf("Total number of words in %s: %d\n", filename, wordCount);
    return EXIT_SUCCESS;
}