//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV file
#define MAX_COLUMNS 10

// Define the maximum length of a line in a CSV file
#define MAX_LINE_LENGTH 1024

// Define the delimiter used to separate columns in a CSV file
#define DELIMITER ','

// Define the structure of a CSV record
typedef struct {
    char *columns[MAX_COLUMNS];
    int num_columns;
} CSVRecord;

// Create a new CSV record
CSVRecord *csv_record_new() {
    CSVRecord *record = malloc(sizeof(CSVRecord));
    record->num_columns = 0;
    return record;
}

// Free a CSV record
void csv_record_free(CSVRecord *record) {
    for (int i = 0; i < record->num_columns; i++) {
        free(record->columns[i]);
    }
    free(record);
}

// Read a line from a CSV file and parse it into a CSV record
CSVRecord *csv_record_read(FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return NULL;
    }

    // Create a new CSV record
    CSVRecord *record = csv_record_new();

    // Parse the line into columns
    char *token = strtok(line, DELIMITER);
    while (token != NULL) {
        record->columns[record->num_columns++] = strdup(token);
        token = strtok(NULL, DELIMITER);
    }

    return record;
}

// Print a CSV record to stdout
void csv_record_print(CSVRecord *record) {
    for (int i = 0; i < record->num_columns; i++) {
        printf("%s", record->columns[i]);
        if (i < record->num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// Read a CSV file and print its contents to stdout
void csv_file_read(FILE *file) {
    // Read the first line of the file to get the number of columns
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return;
    }

    // Parse the line into columns
    char *token = strtok(line, DELIMITER);
    int num_columns = 0;
    while (token != NULL) {
        num_columns++;
        token = strtok(NULL, DELIMITER);
    }

    // Read the rest of the file and print its contents to stdout
    CSVRecord *record;
    while ((record = csv_record_read(file)) != NULL) {
        csv_record_print(record);
        csv_record_free(record);
    }
}

// Main function
int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the CSV file and print its contents to stdout
    csv_file_read(file);

    // Close the CSV file
    fclose(file);

    return EXIT_SUCCESS;
}