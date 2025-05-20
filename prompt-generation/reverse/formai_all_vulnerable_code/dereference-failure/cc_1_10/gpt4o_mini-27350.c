//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1000
#define MAX_LINE 100
#define MAX_SUMMARY_LINES 5

// Function to count the number of words in a given line
int countWords(const char *line) {
    int count = 0;
    int inWord = 0;

    while (*line) {
        if (*line == ' ' || *line == '\n' || *line == '\t') {
            inWord = 0;
        } else {
            if (inWord == 0) {
                count++;
            }
            inWord = 1;
        }
        line++;
    }
    return count;
}

// Function to summarize the text based on the number of lines specified
void summarizeText(char text[MAX_LINE][MAX_CHAR], int totalLines) {
    int summaryCount = 0;

    printf("\n--- Summary ---\n");

    for (int i = 0; i < totalLines; i++) {
        if (summaryCount < MAX_SUMMARY_LINES) {
            if (countWords(text[i]) > 0) {
                printf("%s\n", text[i]);
                summaryCount++;
            }
        } else {
            break;
        }
    }

    if (summaryCount == 0) {
        printf("No content for summary.\n");
    }
}

// Function to read the entire text file into an array of strings
int readTextFile(const char *filename, char text[MAX_LINE][MAX_CHAR]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int lineCount = 0;
    while (lineCount < MAX_LINE && fgets(text[lineCount], MAX_CHAR, file) != NULL) {
        lineCount++;
    }

    fclose(file);
    return lineCount;
}

// Function to get file name from user
void getFileName(char *filename) {
    printf("Enter the file name (including .txt): ");
    fgets(filename, MAX_CHAR, stdin);
    size_t len = strlen(filename);
    if (filename[len - 1] == '\n') {
        filename[len - 1] = '\0'; // Remove newline
    }
}

int main() {
    char filename[MAX_CHAR];
    char text[MAX_LINE][MAX_CHAR];
    
    getFileName(filename);
    
    int totalLines = readTextFile(filename, text);
    if (totalLines == -1) {
        return EXIT_FAILURE;
    }

    printf("\n--- Original Text ---\n");
    for (int i = 0; i < totalLines; i++) {
        printf("%s", text[i]);
    }

    summarizeText(text, totalLines);

    return EXIT_SUCCESS;
}