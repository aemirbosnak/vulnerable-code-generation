//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is a word delimiter
bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == ',' || ch == '.' || ch == ';' || ch == '!' || ch == '?' || ch == '"';
}

// Function to count the words in a string
int countWordsInString(const char *str) {
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isDelimiter(str[i])) {
            if (inWord) {
                count++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

// Function to read file contents and count words
int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *buffer = NULL;
    size_t bufsize = 0;
    int totalCount = 0;

    while (getline(&buffer, &bufsize, file) != -1) {
        totalCount += countWordsInString(buffer);
    }
    
    free(buffer);
    fclose(file);
    
    return totalCount;
}

// Main function to execute the word count program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int wordCount = countWordsInFile(filename);
    
    printf("The total number of words in the file '%s' is: %d\n", filename, wordCount);
    
    return EXIT_SUCCESS;
}