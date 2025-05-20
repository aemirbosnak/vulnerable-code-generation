//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

void printCSVRow(char **row, int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        if (row[i] != NULL) {
            printf("%s", row[i]);
        }
        if (i < numColumns - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

char **parseCSVLine(char *line, int *numColumns) {
    char **columns = malloc(MAX_COLUMNS * sizeof(char *));
    if (columns == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, ",");
    int index = 0;

    while (token != NULL) {
        columns[index++] = strdup(token); // Allocate and duplicate token
        token = strtok(NULL, ",");
    }

    *numColumns = index;
    return columns;
}

void freeCSVRow(char **row, int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        free(row[i]); // Free each allocated string
    }
    free(row); // Free the array itself
}

void readCSVFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        // Strip newline character
        line[strcspn(line, "\n")] = 0;

        int numColumns;
        char **row = parseCSVLine(line, &numColumns);
        printf("Row %d: ", lineCount + 1);
        printCSVRow(row, numColumns);
        freeCSVRow(row, numColumns);
        lineCount++;
    }

    fclose(file);
}

int main() {
    const char *filename = "data.csv";

    printf("Reading CSV File: %s\n", filename);
    readCSVFile(filename);

    return 0;
}