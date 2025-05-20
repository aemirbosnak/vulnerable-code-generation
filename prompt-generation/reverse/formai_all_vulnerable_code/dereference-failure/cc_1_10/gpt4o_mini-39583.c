//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

void parseCSVLine(char *line, char *fields[], int *fieldCount) {
    *fieldCount = 0;
    char *token = strtok(line, ",");
    
    while (token != NULL) {
        if (*fieldCount >= MAX_FIELDS) {
            fprintf(stderr, "Error: Too many fields in CSV line\n");
            exit(EXIT_FAILURE);
        }
        fields[(*fieldCount)++] = strdup(token);
        token = strtok(NULL, ",");
    }
}

void readCSVFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *fields[MAX_FIELDS];
        int fieldCount = 0;

        // Remove newline character from the end of line if present
        line[strcspn(line, "\n")] = 0;

        parseCSVLine(line, fields, &fieldCount);
        for (int i = 0; i < fieldCount; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
            free(fields[i]); // Free the allocated memory after usage
        }
        printf("Total Fields: %d\n", fieldCount);
        printf("------------------------------------\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *fileName = argv[1];
    
    // Sanitize file name and check for potential risks
    if (strstr(fileName, "../") != NULL || strstr(fileName, "/") == fileName) {
        fprintf(stderr, "Error: Invalid file name provided.\n");
        return EXIT_FAILURE;
    }

    readCSVFile(fileName);
    
    return EXIT_SUCCESS;
}