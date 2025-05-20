//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to parse a single line into an array of strings based on the delimiter
char **parseLine(char *line, const char delimiter, int *columnCount) {
    char **columns = malloc(MAX_COLUMNS * sizeof(char *));
    char *token;
    int count = 0;

    token = strtok(line, &delimiter);
    while (token != NULL && count < MAX_COLUMNS) {
        columns[count] = malloc(strlen(token) + 1);
        strcpy(columns[count], token);
        count++;
        token = strtok(NULL, &delimiter);
    }

    *columnCount = count;
    return columns;
}

// Function to free the memory allocated for the columns
void freeColumns(char **columns, int columnCount) {
    for (int i = 0; i < columnCount; i++) {
        free(columns[i]);
    }
    free(columns);
}

// Function to read CSV from a file
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int columnCount;

    // Read and parse each line from the file
    while (fgets(line, sizeof(line), file)) {
        char **columns = parseLine(line, ',', &columnCount);
        if (columns == NULL) {
            fprintf(stderr, "Error parsing line: %s\n", line);
            continue;
        }

        // Print the parsed columns
        for (int i = 0; i < columnCount; i++) {
            printf("Column %d: %s\n", i + 1, columns[i]);
        }
        
        // Free the memory for current line's columns
        freeColumns(columns, columnCount);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    readCSV(filename);

    return EXIT_SUCCESS;
}