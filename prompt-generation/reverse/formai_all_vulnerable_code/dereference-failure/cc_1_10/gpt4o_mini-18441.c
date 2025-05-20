//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 100
#define MAX_FIELDS 20

// Function to tokenize a CSV line into fields
char **parseCSVLine(char *line, int *fieldCount) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *token;
    int count = 0;

    // Breaking the line by delimiter ','
    token = strtok(line, ",");
    while(token != NULL && count < MAX_FIELDS) {
        fields[count] = malloc(MAX_FIELD_LENGTH * sizeof(char));
        strncpy(fields[count], token, MAX_FIELD_LENGTH);
        fields[count][MAX_FIELD_LENGTH - 1] = '\0'; // Ensure null termination
        count++;
        token = strtok(NULL, ",");
    }
    
    *fieldCount = count;
    return fields;
}

// Function to free allocated memory for fields
void freeFields(char **fields, int fieldCount) {
    for (int i = 0; i < fieldCount; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Main function to read and process CSV file
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    // Header processing (first line)
    if (fgets(line, sizeof(line), file) != NULL) {
        lineNumber++;
        printf("CSV Header: %s", line); // Printing the header
    }

    // Reading each subsequent line
    while (fgets(line, sizeof(line), file) != NULL) {
        lineNumber++;
        int fieldCount = 0;

        // Parse the current line
        char **fields = parseCSVLine(line, &fieldCount);

        // Output the contents of each field
        printf("Line %d: ", lineNumber);
        for (int i = 0; i < fieldCount; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%s", fields[i]);
        }
        printf("\n");

        // Free the memory allocated for fields
        freeFields(fields, fieldCount);
    }

    fclose(file);
    printf("Processed %d lines from %s\n", lineNumber, argv[1]);
    
    return EXIT_SUCCESS;
}