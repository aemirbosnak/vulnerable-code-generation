//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum buffer size for reading lines
#define MAX_LINE_LENGTH 1024

// Define a structure to hold the CSV record
typedef struct {
    char **data; 
    int columns;
} CSVRecord;

// Function to read a line from the file
char *readLine(FILE *file, char *buffer, size_t size) {
    if (fgets(buffer, size, file) == NULL) {
        return NULL; // End of file or error
    }
    return buffer;
}

// Function to split a line into columns based on delimiter
CSVRecord parseLine(char *line) {
    CSVRecord record;
    record.columns = 0;
    record.data = NULL;

    char *token = strtok(line, ",\n");
    while (token != NULL) {
        record.data = realloc(record.data, sizeof(char*) * (++record.columns));
        record.data[record.columns - 1] = strdup(token); // Save a copy of the string
        token = strtok(NULL, ",\n");
    }
    return record;
}

// Function to free the memory allocated for a CSV record
void freeCSVRecord(CSVRecord record) {
    for (int i = 0; i < record.columns; i++) {
        free(record.data[i]);
    }
    free(record.data);
}

// Function to display the CSV record
void displayRecord(CSVRecord record) {
    for (int i = 0; i < record.columns; i++) {
        printf("Column %d: %s\n", i + 1, record.data[i]);
    }
    printf("\n");
}

// Main function to handle CSV reading
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    // Read the file line by line
    while (readLine(file, line, sizeof(line))) {
        lineNumber++;
        printf("Processing line %d:\n", lineNumber);
        
        CSVRecord record = parseLine(line);
        displayRecord(record);
        freeCSVRecord(record);
    }

    fclose(file);
    printf("Finished processing %d lines successfully!\n", lineNumber);
    return EXIT_SUCCESS;
}