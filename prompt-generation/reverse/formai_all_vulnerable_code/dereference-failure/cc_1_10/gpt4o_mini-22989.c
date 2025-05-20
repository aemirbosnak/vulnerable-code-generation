//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function prototypes
void readCSV(const char *filename);
void parseLine(char *line);
void printData(char **data, int columnCount);

int main() {
    const char *filename = "data.csv";
    readCSV(filename);
    return 0;
}

// Function to read the CSV file
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLine(line);
    }

    fclose(file);
}

// Function to parse a line from the CSV
void parseLine(char *line) {
    char *data[MAX_COLUMNS];
    int columnCount = 0;

    char *token = strtok(line, ",");
    while (token != NULL && columnCount < MAX_COLUMNS) {
        data[columnCount] = (char *)malloc(strlen(token) + 1);
        if (data[columnCount] == NULL) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }

        strcpy(data[columnCount], token);
        token = strtok(NULL, ",");
        columnCount++;
    }

    // Print parsed data
    printData(data, columnCount);

    // Free allocated memory
    for (int i = 0; i < columnCount; i++) {
        free(data[i]);
    }
}

// Function to print the data from the CSV
void printData(char **data, int columnCount) {
    printf("Parsed Data:\n");
    for (int i = 0; i < columnCount; i++) {
        // Remove newline character if present
        char *newline_pos = strchr(data[i], '\n');
        if (newline_pos) {
            *newline_pos = '\0';
        }
        printf("[%d] %s\n", i, data[i]);
    }
    printf("\n");
}