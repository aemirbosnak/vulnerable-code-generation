//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

// Function Prototypes
void parseCSVLine(char *line, char ***fields, int *numFields);
void freeFields(char **fields, int numFields);
void printFields(char **fields, int numFields);

int main(int argc, char *argv[]) {
    // Check if the filename is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    // Reading the file line by line
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
        char **fields = NULL;
        int numFields = 0;

        // Parse the line into fields
        parseCSVLine(line, &fields, &numFields);

        // Print the fields
        printf("Line %d:\n", lineCount);
        printFields(fields, numFields);
        printf("\n");

        // Free allocated memory for fields
        freeFields(fields, numFields);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

// Function to parse a CSV line into fields
void parseCSVLine(char *line, char ***fields, int *numFields) {
    char *token;
    int count = 0;
    char **tempFields = malloc(MAX_FIELD_LENGTH * sizeof(char *));
    
    // Check if memory allocation was successful
    if (!tempFields) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Tokenize the line using comma as a delimiter
    token = strtok(line, ",");
    while (token) {
        token[strcspn(token, "\n")] = 0; // Remove newline character
        tempFields[count] = strdup(token); // Duplicate the string
        if (!tempFields[count]) {
            fprintf(stderr, "Memory allocation failed for field\n");
            exit(EXIT_FAILURE);
        }
        count++;
        token = strtok(NULL, ",");
    }

    *fields = tempFields;
    *numFields = count;
}

// Function to print the fields
void printFields(char **fields, int numFields) {
    for (int i = 0; i < numFields; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
}

// Function to free allocated memory for fields
void freeFields(char **fields, int numFields) {
    for (int i = 0; i < numFields; i++) {
        free(fields[i]); // Free each field
    }
    free(fields); // Free the array of fields
}