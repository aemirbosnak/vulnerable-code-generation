//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_BUFFER_SIZE 1024

void countWordsInLine(const char *line, int *wordCount) {
    int inWord = 0;
    *wordCount = 0;

    while (*line) {
        if (*line == ' ' || *line == '\n' || *line == '\t') {
            inWord = 0; // We're no longer in a word
        } else {
            if (inWord == 0) {
                inWord = 1; // A new word starts
                (*wordCount)++;
            }
        }
        line++;
    }
}

void displayUsage(const char *programName) {
    printf("Usage: %s <file_name>\n", programName);
    printf("Count the number of words in the specified text file.\n");
}

int countWordsInFile(const char *fileName) {
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];
    int totalWordCount = 0;

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Return an error code
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int wordCountInLine;
        countWordsInLine(buffer, &wordCountInLine);
        totalWordCount += wordCountInLine;
    }

    fclose(file);
    return totalWordCount;
}

void printArt() {
    printf("\n");
    printf("   __        __                     _               \n");
    printf("   \\ \\      / /                    | |              \n");
    printf("    \\ \\ /\\ / /__  _ __ ___   __ _| |__   ___ _ __  \n");
    printf("     \\ V  V / _ \\| '_ ` _ \\ / _` | '_ \\ / _ \\ '_ \\ \n");
    printf("      \\_/\\_/ (_) | | | | | | (_| | | | |  __/ | | |\n");
    printf("                   |_| |_| |_|\\__, |_| |_|\\___|_| |_| \n");
    printf("                               __/ |                      \n");
    printf("                              |___/                       \n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char fileName[MAX_FILE_NAME];
    strncpy(fileName, argv[1], MAX_FILE_NAME - 1);
    fileName[MAX_FILE_NAME - 1] = '\0'; // Ensuring null termination

    printArt();

    int wordCount = countWordsInFile(fileName);
    if (wordCount == -1) {
        return EXIT_FAILURE; // Handle the file error if occurred
    }

    printf("\nTotal number of words in '%s': %d\n", fileName, wordCount);
    return EXIT_SUCCESS;
}