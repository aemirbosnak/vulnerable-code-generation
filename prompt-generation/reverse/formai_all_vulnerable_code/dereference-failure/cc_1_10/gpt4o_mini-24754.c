//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to parse a line into fields based on a delimiter
int parseLine(char *line, char fields[][MAX_LINE_LENGTH], const char delimiter) {
    int fieldCount = 0;
    char *token = strtok(line, &delimiter);
    
    while (token != NULL && fieldCount < MAX_FIELDS) {
        strncpy(fields[fieldCount], token, MAX_LINE_LENGTH);
        fields[fieldCount][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-termination
        fieldCount++;
        token = strtok(NULL, &delimiter);
    }
    
    return fieldCount;
}

// Function to read a CSV file and print its contents
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_LINE_LENGTH];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        // Remove newline character at the end
        line[strcspn(line, "\n")] = '\0';
        
        int fieldCount = parseLine(line, fields, ','); // Assume comma as separator
        
        printf("Line %d:\n", lineNumber);
        for (int i = 0; i < fieldCount; i++) {
            printf("  Field %d: %s\n", i + 1, fields[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Main function to execute CSV reader
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    readCSV(argv[1]);

    return EXIT_SUCCESS;
}