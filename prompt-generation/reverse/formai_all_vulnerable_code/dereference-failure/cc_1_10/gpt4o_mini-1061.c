//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 1024

void displayUsage() {
    printf("Usage: wordcount <filename>\n");
    printf("Counts the number of words, lines, and characters in the specified file.\n");
}

int isWordCharacter(char c) {
    return isalnum(c) || c == '\'';
}

void countFileContents(const char *filename, long *wordCount, long *lineCount, long *charCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    int inWord = 0;

    while (fgets(line, sizeof(line), file)) {
        (*lineCount)++;
        (*charCount) += strlen(line);

        for (int i = 0; line[i] != '\0'; i++) {
            if (isWordCharacter(line[i])) {
                if (!inWord) {
                    inWord = 1; // Start of a new word
                    (*wordCount)++;
                }
            } else {
                inWord = 0; // End of current word
            }
        }
    }

    fclose(file);
}

void printCounts(const char *filename, long wordCount, long lineCount, long charCount) {
    printf("File: %s\n", filename);
    printf("Lines: %ld\n", lineCount);
    printf("Words: %ld\n", wordCount);
    printf("Characters: %ld\n", charCount);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char filename[MAX_FILENAME_LENGTH];
    strcpy(filename, argv[1]);

    long wordCount = 0, lineCount = 0, charCount = 0;

    countFileContents(filename, &wordCount, &lineCount, &charCount);
    printCounts(filename, wordCount, lineCount, charCount);

    return EXIT_SUCCESS;
}