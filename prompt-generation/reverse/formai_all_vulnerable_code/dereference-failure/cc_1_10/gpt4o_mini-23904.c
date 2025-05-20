//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void countWordsAndLines(const char *filename, int *wordCount, int *lineCount, int *charCount) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    *wordCount = 0;
    *lineCount = 0;
    *charCount = 0;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        (*lineCount)++;
        *charCount += strlen(line);

        // Count words in the current line
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            (*wordCount)++;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
}

void displayCounts(const char *filename, int wordCount, int lineCount, int charCount) {
    printf("\n--- Word Count Results for %s ---\n", filename);
    printf("Total Lines:   %d\n", lineCount);
    printf("Total Words:   %d\n", wordCount);
    printf("Total Characters: %d\n", charCount);
    printf("------------------------------------\n");
}

char *promptFileName() {
    char *filename = malloc(256 * sizeof(char));
    if (filename == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the filename to count words (including the path if not in the current directory): ");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character
    return filename;
}

int main() {
    int wordCount, lineCount, charCount;
    char *filename;

    printf("Welcome to the Genius Word Count Tool!\n");
    printf("Your text adventure begins now...\n");

    filename = promptFileName();
    countWordsAndLines(filename, &wordCount, &lineCount, &charCount);
    displayCounts(filename, wordCount, lineCount, charCount);

    free(filename);
    return 0;
}