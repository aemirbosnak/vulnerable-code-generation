//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

// Structure to hold word count statistics
typedef struct WordCount {
    int wordCount;
    int lineCount;
    int characterCount;
} WordCount;

// Function to initialize WordCount structure
void initWordCount(WordCount *wc) {
    wc->wordCount = 0;
    wc->lineCount = 0;
    wc->characterCount = 0;
}

// Function to count words, lines, and characters in a file
void countWordsInFile(const char *filename, WordCount *wc) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int inWord = 0;

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        wc->lineCount++;
        wc->characterCount += strlen(line);
        
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i])) {
                inWord = 0;
            } else if (!inWord) {
                inWord = 1;
                wc->wordCount++;
            }
        }
    }
    fclose(file);
}

// Function to print the results in a creative format
void printResults(const char *filename, WordCount *wc) {
    printf("-------------------------------------------------\n");
    printf("              Word Count Report                  \n");
    printf("-------------------------------------------------\n");
    printf("File Name: %s\n", filename);
    printf("Total Lines: %d\n", wc->lineCount);
    printf("Total Words: %d\n", wc->wordCount);
    printf("Total Characters: %d\n", wc->characterCount);
    printf("-------------------------------------------------\n");
}

// Main function to execute the word count tool
int main(int argc, char *argv[]) {
    WordCount wc;
    char filename[MAX_FILENAME_LENGTH];

    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Get the filename from command line argument
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH);
    filename[MAX_FILENAME_LENGTH - 1] = '\0'; // Ensure null-termination

    // Initialize WordCount statistics
    initWordCount(&wc);
    
    // Count words in the specified file
    countWordsInFile(filename, &wc);
    
    // Print the results in a friendly way
    printResults(filename, &wc);
    
    return EXIT_SUCCESS;
}