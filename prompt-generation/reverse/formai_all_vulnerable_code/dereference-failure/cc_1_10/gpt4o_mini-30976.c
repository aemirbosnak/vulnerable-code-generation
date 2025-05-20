//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 100

void writeToFile(const char *filename, const char *lines[], int lineCount) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);
    printf("Successfully written %d lines to %s\n", lineCount, filename);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    printf("Contents of %s:\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    printf("Finished reading %s\n", filename);
}

void appendToFile(const char *filename, const char *newLine) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", newLine);
    fclose(file);
    printf("Successfully appended line to %s\n", filename);
}

int main() {
    const char *filename = "example.txt";
    const char *lines[MAX_LINES];
    int lineCount = 0;

    printf("Please enter up to %d lines of text (blank line to finish):\n", MAX_LINES);
    while (lineCount < MAX_LINES) {
        char input[MAX_LINE_LENGTH];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Error or EOF
        }

        // Remove the newline character from fgets
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            break; // Blank line signifies end of input
        }

        lines[lineCount] = strdup(input);
        if (lines[lineCount] == NULL) {
            printf("Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        lineCount++;
    }

    writeToFile(filename, lines, lineCount);
    
    printf("\nNow reading back the content of the file:\n");
    readFile(filename);
    
    char newLine[MAX_LINE_LENGTH];
    printf("\nEnter a new line to append to the file: ");
    if (fgets(newLine, sizeof(newLine), stdin) != NULL) {
        newLine[strcspn(newLine, "\n")] = 0; // Remove newline
        appendToFile(filename, newLine);
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < lineCount; i++) {
        free((void *)lines[i]);
    }

    return 0;
}