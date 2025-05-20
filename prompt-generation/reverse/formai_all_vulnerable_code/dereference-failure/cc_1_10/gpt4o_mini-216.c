//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

void handleError(const char *msg) {
    fprintf(stderr, "Error: %s - %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void readLines(FILE *file, char lines[MAX_LINES][LINE_LENGTH], int *lineCount) {
    char buffer[LINE_LENGTH];

    *lineCount = 0;
    while (fgets(buffer, LINE_LENGTH, file) != NULL) {
        if (*lineCount >= MAX_LINES) {
            handleError("Exceeded maximum number of lines.");
        }
        strcpy(lines[*lineCount], buffer);
        (*lineCount)++;
    }

    if (ferror(file)) {
        handleError("Error reading from file.");
    }
}

void writeLines(FILE *file, char lines[MAX_LINES][LINE_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        if (fputs(lines[i], file) == EOF) {
            handleError("Error writing to file.");
        }
    }
}

void processLines(char lines[MAX_LINES][LINE_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        // Simulating processing by converting to uppercase
        for (char *p = lines[i]; *p; p++) {
            *p = (*p >= 'a' && *p <= 'z') ? *p - 'a' + 'A' : *p;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        handleError("Failed to open input file");
    }

    char lines[MAX_LINES][LINE_LENGTH];
    int lineCount;

    readLines(inputFile, lines, &lineCount);
    fclose(inputFile);

    processLines(lines, lineCount);

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        handleError("Failed to open output file");
    }

    writeLines(outputFile, lines, lineCount);
    fclose(outputFile);

    printf("Processing complete. %d lines processed.\n", lineCount);
    return EXIT_SUCCESS;
}