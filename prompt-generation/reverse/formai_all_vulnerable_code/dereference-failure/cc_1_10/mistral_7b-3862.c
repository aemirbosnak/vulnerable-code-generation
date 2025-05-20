//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 5

// Function to read a line from a file
char *readline(FILE *file) {
    size_t len = 0;
    size_t cap = MAX_LINE_LENGTH;
    char *line = malloc(cap);
    char c;
    int atEnd = 0;

    while (!atEnd && (c = fgetc(file)) != EOF && len < cap - 1) {
        line[len] = c;
        len++;

        if (c == '\n') {
            atEnd = 1;
            line[len] = '\0';
        } else {
            cap *= 2;
            line = realloc(line, cap);
        }
    }

    if (len > MAX_LINE_LENGTH) {
        fprintf(stderr, "Line too long\n");
        free(line);
        line = NULL;
    }

    return line;
}

// Function to write a line to a file
void writeline(FILE *file, const char *line) {
    size_t len = strlen(line);

    if (fputs(line, file) == EOF) {
        fprintf(stderr, "Error writing to file\n");
    }

    if (fputc('\n', file) == EOF) {
        fprintf(stderr, "Error writing to file\n");
    }
}

int main(int argc, char **argv) {
    FILE *inputFile = NULL;
    FILE *outputFile = NULL;
    char line[MAX_NUM_LINES][MAX_LINE_LENGTH];
    int numLines = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputFile outputFile\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files\n");
        if (inputFile != NULL) {
            fclose(inputFile);
        }
        if (outputFile != NULL) {
            fclose(outputFile);
        }
        return 1;
    }

    while (fgets(line[numLines], MAX_LINE_LENGTH, inputFile) != NULL) {
        numLines++;
    }

    for (int i = 0; i < numLines; i++) {
        writeline(outputFile, line[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    for (int i = 0; i < numLines; i++) {
        free(line[i]);
    }
    free(line);

    printf("File copied successfully\n");

    return 0;
}